#pragma once

#include "IModule.hpp"
#include "Pkcs11Module.hpp"

namespace minihsm {
class CryptoEngine : public IModule {
public:
  CryptoEngine();
  bool initialize() override;
  void shutdown() override;

private:
  Pkcs11Module pkcs11Module_;
};
} // namespace minihsm
