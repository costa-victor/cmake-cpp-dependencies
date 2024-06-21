#include "libShape/someLibShape.hpp"

class DemoLibShape : public libShape::someLibShape {
    public:
        DemoLibShape();
        void abstractPublicHello() override;

    protected:
        int version;
        int getVersion() override;
};
