#include "Serialize.hpp"

Serialize::Serialize(void)
{
    //std::cout << "default Serialize constructor called" << std::endl;
}

Serialize::Serialize(const Serialize &rhs)
{
   // std::cout << "Serialize copy constructror called" << std::endl;
    *this = rhs;
}

Serialize &Serialize::operator=(const Serialize &rhs)
{
    //std::cout << "Serialize copy assignment operator called" << std::endl;
    (void)rhs;
    return(*this);
}

Serialize::~Serialize(void)
{
    //std::cout << "Serialize destructor called" << std::endl;
}

uintptr_t Serialize::serialize(Data* ptr)
{
    uintptr_t i;
    i = reinterpret_cast<std::uintptr_t>(ptr);
    return (i);
}

Data* Serialize::deserialize(uintptr_t raw)
{
    Data *data;
    data = reinterpret_cast<Data*>(raw);
    return (data);
}
