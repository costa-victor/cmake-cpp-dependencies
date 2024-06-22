#include "someLibC.hpp"
#include <iostream>

// External dependency
#include "someLibA/someLibA.hpp"

namespace libC {
    SomeLibC::SomeLibC() {
        std::cout << "Hello from libC constructor using libA ::: " << std::endl;
        libA::someLibA_fnc();
        version = 42;
    }
    void SomeLibC::abstractPublicHello() {
        std::cout << "Hello from the abstract public function in libC ::: " << getVersion() << std::endl;
    }
    int SomeLibC::getVersion() {
        return version;
    }
}