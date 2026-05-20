#pragma  once
#include  <iostream>
#include  <stdlib.h>
#include  <stdint.h>

class  Base
{
    public:
        virtual  ~Base();
};
Base * generate(void);
void identify(Base* p);
void identify(Base& p);  
