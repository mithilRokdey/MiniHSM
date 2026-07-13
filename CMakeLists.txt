cmake_minimum_required(VERSION 3.16)
project(MiniHSM LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(PkgConfig REQUIRED)

option(ENABLE_PKCS11 "Enable PKCS#11 support" OFF)
pkg_check_modules(P11 QUIET libp11)

if(ENABLE_PKCS11 AND P11_FOUND)
  message(STATUS "PKCS#11 support enabled (libp11 found)")
  add_compile_definitions(MINIHSM_HAS_PKCS11=1)
else()
  if(ENABLE_PKCS11 AND NOT P11_FOUND)
    message(WARNING "PKCS#11 support requested but libp11 not found; disabling")
  else()
    message(STATUS "PKCS#11 support disabled")
  endif()
  add_compile_definitions(MINIHSM_HAS_PKCS11=0)
endif()

add_executable(minihsm
  src/main.cpp
  src/MiniHSM.cpp
  src/SessionManager.cpp
  src/AuthorizationManager.cpp
  src/PolicyEngine.cpp
  src/WorkflowManager.cpp
  src/ExecutionManager.cpp
  src/CryptoEngine.cpp
  src/KeyManager.cpp
  src/KeyVault.cpp
  src/AuditManager.cpp
)

target_include_directories(minihsm PRIVATE include)

if(P11_FOUND AND ENABLE_PKCS11)
  target_sources(minihsm PRIVATE src/Pkcs11Module.cpp)
  target_include_directories(minihsm PRIVATE ${P11_INCLUDE_DIRS} /usr/include/p11-kit-1)
  target_compile_options(minihsm PRIVATE ${P11_CFLAGS_OTHER})
  target_link_libraries(minihsm PRIVATE ${P11_LIBRARIES})
  target_link_options(minihsm PRIVATE ${P11_LDFLAGS_OTHER})
endif()

target_link_libraries(minihsm PRIVATE dl)
