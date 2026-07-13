#include "CryptoEngine.hpp"

#include <iostream>

namespace minihsm {
CryptoEngine::CryptoEngine() = default;

bool CryptoEngine::initialize() {
#if MINIHSM_HAS_PKCS11
  if (!pkcs11Module_.initialize()) {
    std::cerr << "PKCS#11 initialization failed: " << pkcs11Module_.lastError() << "\n";
    return false;
  }
  std::cout << "PKCS#11 support initialized.\n";
  return true;
#else
  std::cout << "PKCS#11 support is not available in this build.\n";
  return true;
#endif
}

void CryptoEngine::shutdown() {
  pkcs11Module_.shutdown();
}
} // namespace minihsm
