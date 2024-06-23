#ifndef SOMELIB_C_HPP
#define SOMELIB_C_HPP
// External dependency
#include "libShape/someLibShape.hpp"

namespace libC {
    class SomeLibC : public libShape::someLibShape {
        public:
            SomeLibC();
            void abstractPublicHello() override;

        protected:
            int version;
            int getVersion() override;
    };
}

#endif  // SOMELIB_C_HPP