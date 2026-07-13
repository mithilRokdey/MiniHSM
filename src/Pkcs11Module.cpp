#include "Pkcs11Module.hpp"

#include <dlfcn.h>
#include <iostream>
#include <p11-kit/pkcs11.h>
#include <utility>

namespace minihsm {
namespace {
using GetFunctionListFn = CK_RV (*)(CK_FUNCTION_LIST_PTR_PTR);
}

Pkcs11Module::Pkcs11Module(std::string libraryPath)
    : libraryPath_(std::move(libraryPath)), initialized_(false) {}

bool Pkcs11Module::initialize() {
  if (initialized_) {
    return true;
  }

  if (libraryPath_.empty()) {
    libraryPath_ = "/usr/lib/x86_64-linux-gnu/softhsm/libsofthsm2.so";
  }

  void* handle = dlopen(libraryPath_.c_str(), RTLD_NOW | RTLD_LOCAL);
  if (!handle) {
    lastError_ = dlerror();
    std::cerr << "PKCS#11 module load failed: " << lastError_ << "\n";
    return false;
  }

  auto* getFunctionList = reinterpret_cast<GetFunctionListFn>(dlsym(handle, "C_GetFunctionList"));
  if (!getFunctionList) {
    lastError_ = "C_GetFunctionList not found";
    std::cerr << lastError_ << "\n";
    dlclose(handle);
    return false;
  }

  CK_FUNCTION_LIST_PTR functionList = nullptr;
  CK_RV rv = getFunctionList(&functionList);
  if (rv != CKR_OK) {
    lastError_ = "C_GetFunctionList failed";
    std::cerr << lastError_ << "\n";
    dlclose(handle);
    return false;
  }

  rv = functionList->C_Initialize(nullptr);
  if (rv != CKR_OK && rv != CKR_CRYPTOKI_ALREADY_INITIALIZED) {
    lastError_ = "C_Initialize failed with error code " + std::to_string(rv);
    std::cerr << lastError_ << "\n";
    dlclose(handle);
    return false;
  }

  initialized_ = true;
  lastError_.clear();
  return true;
}

void Pkcs11Module::shutdown() {
  initialized_ = false;
}

bool Pkcs11Module::isInitialized() const {
  return initialized_;
}

const std::string& Pkcs11Module::lastError() const {
  return lastError_;
}
} // namespace minihsm
