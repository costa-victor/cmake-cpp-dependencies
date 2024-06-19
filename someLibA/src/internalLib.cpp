#include <iostream>

namespace libA {
    namespace internal {
        void helloFromInternal(void) {
            std::cout << "Hello from somelibA::internal" << std::endl;
        }
    }
}