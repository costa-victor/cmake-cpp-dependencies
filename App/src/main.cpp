#include "someLibC/someLibC.hpp"
#include "someLibB/someLibB.hpp"
#include "someLibA/someLibA.hpp"

int main(void)
{
    libB::someLibB_fnc();
    libA::someLibA_fnc();
    libC::SomeLibC obj;
    obj.abstractPublicHello();
    return 0;
}
