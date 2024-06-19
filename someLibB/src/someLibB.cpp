#include "someLibB.hpp"
#include "internalLib.hpp"
#include <iostream>

// External dependency
#include "someLibA/someLibA.hpp"

namespace libB {
    void someLibB_fnc(void) {
        std::cout << "Hello from somelibB" << std::endl;
        libB::internal::helloFromInternal();
        libA::someLibA_fnc();
    }
}