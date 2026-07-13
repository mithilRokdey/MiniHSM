#pragma once

#include "IModule.hpp"

namespace minihsm {
class AuditManager : public IModule {
public:
  AuditManager();
  bool initialize() override;
  void shutdown() override;
};
} // namespace minihsm
