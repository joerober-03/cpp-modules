#include "Serialize.hpp"

int main()
{
    Data data;
    data.a = 5;
    data.b = "hello";
    data.c = 3.3;
    std::cout << "before serialization:" << std::endl;
    std::cout << "int: " << data.a << std::endl;
    std::cout << "string: " << data.b << std::endl;
    std::cout << "double: " << data.c << std::endl;

    uintptr_t uin;
    uin = Serialize::serialize(&data);
    Data *data2;
    data2 = Serialize::deserialize(uin);
    std::cout << "after serialization:" << std::endl;
    std::cout << "int: " << data2->a << std::endl;
    std::cout << "string: " << data2->b << std::endl;
    std::cout << "double: " << data2->c << std::endl;
    return 0;
}