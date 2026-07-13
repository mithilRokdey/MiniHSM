#pragma once

#include "IModule.hpp"

namespace minihsm {
class WorkflowManager : public IModule {
public:
  WorkflowManager();
  bool initialize() override;
  void shutdown() override;
};
} // namespace minihsm
