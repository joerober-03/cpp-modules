#pragma once

#include <iostream>
#include <stdint.h>

typedef struct Data
{
    int a;
    std::string b;
    double c;
}               Data;

class Serialize
{
    private:

    Serialize();
    Serialize(const Serialize &rhs);
    Serialize &operator=(const Serialize &rhs);
    ~Serialize();

    public:

    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};