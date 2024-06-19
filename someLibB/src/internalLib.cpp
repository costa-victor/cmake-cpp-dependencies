#include <iostream>

namespace libB {
    namespace internal {
        void helloFromInternal(void) {
            std::cout << "Hello from somelibB::internal" << std::endl;
        }
    }
}