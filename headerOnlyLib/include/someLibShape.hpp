#ifndef SOMELIB_SHAPE_HPP
#define SOMELIB_SHAPE_HPP

namespace libShape {
    // Abstract class
    class someLibShape {
        public:
            // Pure virtual public function
            virtual void abstractPublicHello() = 0;

        protected:
            // Pure virtual protected
            int version;
            virtual int getVersion() = 0;
    };
}

#endif  // SOMELIB_SHAPE_HPP