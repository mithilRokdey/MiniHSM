#include "MiniHSM.hpp"

#include <iostream>

namespace minihsm {
MiniHSM::MiniHSM() = default;

bool MiniHSM::initialize() {
  std::cout << "Initializing MiniHSM...\n";

  sessionManager.initialize();
  authorizationManager.initialize();
  policyEngine.initialize();
  workflowManager.initialize();
  executionManager.initialize();
  cryptoProvider.initialize();
  keyManager.initialize();
  keyVault.initialize();
  auditManager.initialize();

  std::cout << "MiniHSM Ready.\n";
  return true;
}

void MiniHSM::shutdown() {
}
} // namespace minihsm
