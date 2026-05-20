#include  "Base.hpp"
#include  "A.hpp"
#include  "B.hpp"
#include "C.hpp"

Base::~Base()
{
    std::cout  <<  "The  Destractor Base  called\n";
}
Base * generate(void)
{
    srand(time(NULL));
    Base  *obj;
    int  r =  rand() % 3;
    if(r == 1)
        obj =  new A(); 
    else  if(!r)
        obj = new B();
    else
        obj =  new C();
    return obj;
}


void identify(Base* p)
{
    if      (dynamic_cast<A*>(p)) std::cout  << "Its : A\n";
    else if (dynamic_cast<B*>(p)) std::cout  << "Its : B\n";
    else if (dynamic_cast<C*>(p)) std::cout  << "Its : C\n";
    else
        std::cout  << "Not one of those [A,B,C]\n";
}

void identify(Base& p)
{
    
    try
    {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "Its : B\n";
        return;
    }
    catch (...) {
        std::cout <<  "An  exception  throwed for B\n";
    }
    
    try
    {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "Its : A\n";
        return;
    }
    catch (...) {
                std::cout <<  "An exception throwed for A\n";
    }
    try
    {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "Its : C\n";
    }
    catch (...) {
        std::cout <<  "An exception throwed for C\n";
    }
}