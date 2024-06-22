#include "someLibC.hpp"
#include <iostream>

namespace libC {
    SomeLibC::SomeLibC() {
        std::cout << "Hello from libC constructor ::: " << std::endl;
        version = 42;
    }
    void SomeLibC::abstractPublicHello() {
        std::cout << "Hello from the abstract public function in libC ::: " << getVersion() << std::endl;
    }
    int SomeLibC::getVersion() {
        return version;
    }
}