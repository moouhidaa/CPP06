#include  "ScalarConverter.hpp"

int  main(int ac ,char  **av)
{
    (void)ac;
    if( !av[1])
    {
        std::cout  << "Wrong Number Of ARGS\n";
        return (1);
    }
    ScalarConverter n;
    std::string  a(av[1]);
    n.convert(a);
}