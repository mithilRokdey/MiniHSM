#pragma once

#include <string>

namespace minihsm {
// If PKCS#11 support is disabled at build time provide a lightweight inline stub
#if defined(MINIHSM_HAS_PKCS11) && (MINIHSM_HAS_PKCS11==1)
class Pkcs11Module {
public:
  explicit Pkcs11Module(std::string libraryPath = "");

  bool initialize();
  void shutdown();
  bool isInitialized() const;
  const std::string& lastError() const;

private:
  std::string libraryPath_;
  bool initialized_;
  std::string lastError_;
};
#else
class Pkcs11Module {
public:
  explicit Pkcs11Module(std::string libraryPath = "") noexcept {}
  bool initialize() noexcept { return false; }
  void shutdown() noexcept {}
  bool isInitialized() const noexcept { return false; }
  const std::string& lastError() const noexcept { static std::string s; return s; }
};
#endif
} // namespace minihsm
