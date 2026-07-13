#pragma once

#include "IModule.hpp"

namespace minihsm {
class AuthorizationManager : public IModule {
public:
  AuthorizationManager();
  bool initialize() override;
  void shutdown() override;
};
} // namespace minihsm
