#include  "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include  "iostream"

int  main(void)
{
    Base  *base = generate();
    identify(base);
    Base &base1 = *base;
    identify(base1);
    delete  base;
}