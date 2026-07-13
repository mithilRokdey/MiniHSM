#pragma once

#include "IModule.hpp"

namespace minihsm {
class SessionManager : public IModule {
public:
  SessionManager();
  bool initialize() override;
  void shutdown() override;
};
} // namespace minihsm
