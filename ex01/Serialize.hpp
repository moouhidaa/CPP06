#include  <iostream>
#include  <string>
#include  <stdint.h>

struct  Data
{
    int  age;
    std::string  name;
    std::string  country;
};


class  Serialize
{
    public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};