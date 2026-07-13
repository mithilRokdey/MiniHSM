#pragma once

#include "IModule.hpp"

namespace minihsm {
class PolicyEngine : public IModule {
public:
  PolicyEngine();
  bool initialize() override;
  void shutdown() override;
};
} // namespace minihsm
