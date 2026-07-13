#pragma once

#include "AuditManager.hpp"
#include "AuthorizationManager.hpp"
#include "CryptoEngine.hpp"
#include "ExecutionManager.hpp"
#include "IModule.hpp"
#include "KeyManager.hpp"
#include "KeyVault.hpp"
#include "PolicyEngine.hpp"
#include "SessionManager.hpp"
#include "WorkflowManager.hpp"

namespace minihsm {
class MiniHSM : public IModule {
public:
  MiniHSM();
  bool initialize() override;
  void shutdown() override;

private:
  SessionManager sessionManager;
  AuthorizationManager authorizationManager;
  PolicyEngine policyEngine;
  WorkflowManager workflowManager;
  ExecutionManager executionManager;
  CryptoEngine cryptoProvider;
  KeyManager keyManager;
  KeyVault keyVault;
  AuditManager auditManager;
};
} // namespace minihsm
