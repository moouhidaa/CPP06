#include  "Serialize.hpp"

int main()
{
    Data  own;
    own.age = 89;
    own.country =  "morocoo";
    own.name =   "mouaad";

    uintptr_t  i =  Serialize::serialize(&own);
   Data *on  =  Serialize::deserialize(i);
   
   std::cout  <<  on->name << " "<< on->age  <<" " << on->country << std::endl;
}