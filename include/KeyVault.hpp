#pragma once

#include "IModule.hpp"

namespace minihsm {
class KeyVault : public IModule {
public:
  KeyVault();
  bool initialize() override;
  void shutdown() override;
};
} // namespace minihsm
