#include "someLibC.hpp"
#include <iostream>

// External dependency
#include "someLibB/someLibB.hpp"
// #include "someLibA/someLibA.hpp"

namespace libC {
    SomeLibC::SomeLibC() {
        std::cout << "Hello from libC constructor using libB + libA" << std::endl;
        libB::someLibB_fnc();
        // libA::someLibA_fnc();
        version = 42;
    }
    void SomeLibC::abstractPublicHello() {
        std::cout << "Hello from the abstract public function in libC ::: " << getVersion() << std::endl;
    }
    int SomeLibC::getVersion() {
        return version;
    }
}