
#include "demoLib.hpp"
#include <iostream>

// Simple definitions of the class
DemoLibShape::DemoLibShape() {
    version = 42;
}
void DemoLibShape::abstractPublicHello() {
    std::cout << "Hello from the abstract public function ::: " << getVersion() << std::endl;
}
int DemoLibShape::getVersion() {
    return version;
}


int main(void)
{
    DemoLibShape demo;
    demo.abstractPublicHello();
    return 0;
}
