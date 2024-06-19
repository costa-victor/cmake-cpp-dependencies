#include "someLibA.hpp"
#include "internalLib.hpp"
#include <iostream>

namespace libA {
    void someLibA_fnc(void) {
        std::cout << "Hello from somelibA" << std::endl;
        libA::internal::helloFromInternal();
    }
}