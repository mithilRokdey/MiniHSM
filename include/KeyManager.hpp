#pragma once

#include "IModule.hpp"

namespace minihsm {
class KeyManager : public IModule {
public:
  KeyManager();
  bool initialize() override;
  void shutdown() override;
};
} // namespace minihsm
