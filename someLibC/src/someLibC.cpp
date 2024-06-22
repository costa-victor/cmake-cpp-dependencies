#include "someLibC.hpp"
#include <iostream>

namespace libC {
    SomeLibC::SomeLibC() {
        version = 42;
    }
    void SomeLibC::abstractPublicHello() {
        std::cout << "Hello from the abstract public function ::: " << getVersion() << std::endl;
    }
    int SomeLibC::getVersion() {
        return version;
    }
}