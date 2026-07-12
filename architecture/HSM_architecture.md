# MiniHSM Architecture

---

# 1. Purpose

MiniHSM is an educational implementation of a Hardware Security Module (HSM)
designed to explore the architectural principles behind enterprise-grade
CloudHSM solutions.

The objective is not to build a FIPS-certified product, but to understand
how modern HSMs manage cryptographic operations, protect keys, enforce
security policies, and provide high availability.

---

# 2. Design Goals

## Functional Requirements

- Secure key generation
- Secure key storage
- Cryptographic operations
- Key lifecycle management
- PKCS#11-like interface
- Audit logging
- Recovery after failures

## Non-Functional Requirements

- Security-first architecture
- High throughput
- Low latency
- High availability
- Recoverability
- Scalability
- Minimal Trusted Computing Base
- Modular design



# 3. High-Level Architecture

The following block diagram illustrates the main control and cryptographic components in MiniHSM:

```mermaid
flowchart TD
    Client["Client Applications"]
    PKCS11["PKCS#11 / JCE / OpenSSL"]

    TV["Transport Validation"]

    subgraph TCB["Secure Boundary / Trusted Computing Base"]
        Session["Authentication & Session Manager"]
        Auth["Authorization Manager"]
        Policy["Policy Engine"]
        Workflow["Workflow Manager"]
        Exec["Execution Manager"]

        RSAQ["RSA Scheduler"]
        ECCQ["ECC Scheduler"]
        AESQ["AES Scheduler"]

        RSA["RSA Engine"]
        ECC["ECC Engine"]
        AES["AES Engine"]

        KM["Key Manager"]
        KV["Key Vault"]

        Audit["Audit Manager"]
        Recovery["Recovery Manager"]
        Health["Health Manager"]
    end

    Client --> PKCS11
    PKCS11 --> TV
    TV --> Session
    Session --> Auth
    Auth --> Policy
    Policy --> Workflow
    Workflow --> Exec

    Exec --> RSAQ
    Exec --> ECCQ
    Exec --> AESQ

    RSAQ --> RSA
    ECCQ --> ECC
    AESQ --> AES

    RSA --> KM
    ECC --> KM
    AES --> KM

    KM --> KV

    KM --> Audit
    Audit --> Recovery
    Recovery --> Health
```

# 4. Architectural Principles

1. Secrets never leave the Key Vault.

2. Metadata is managed separately from secret material.

3. Authentication, Authorization and Policy are independent concerns.

4. Every security operation must be auditable.

5. Every transaction must be recoverable.

6. Minimize the Trusted Computing Base.

7. Fail Secure.

8. Every module owns its own state.

9. Build for future algorithms.

10. Separate orchestration from cryptographic computation.