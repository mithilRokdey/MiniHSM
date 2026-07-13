#include <iostream>

#include "MiniHSM.hpp"

int main() {
    minihsm::MiniHSM hsm;

    if (!hsm.initialize())
        return -1;

    hsm.shutdown();
    return 0;
}
