#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
    srand (time(NULL));
    int i = rand() % 3 + 1;
    
    if (i == 1)
        return (new A);
    else if (i == 2)
        return (new B);
    else
        return (new C);
}

void identify(Base* p)
{
    A *a;
    B *b;
    C *c;

    a = dynamic_cast<A*>(p);
    if (a != NULL)
        std::cout << "the type of the object is A!" << std::endl;
    else
    {
        b = dynamic_cast<B*>(p);
        if (b != NULL)
            std::cout << "the type of the object is B!" << std::endl;
        else
        {
            c = dynamic_cast<C*>(p);
            if (c != NULL)
                std::cout << "the type of the object is C!" << std::endl;
        }
    }
}

void identify(Base& p)
{
    A c;
    B d;
    A &a = c;
    B &b = d;

    try
    {
        a = dynamic_cast<A&>(p);
        std::cout << "the type of the object is A!" << std::endl;
    }
    catch(const std::bad_cast& e)
    {
        try
        {
            b = dynamic_cast<B&>(p);
            std::cout << "the type of the object is B!" << std::endl;
        }
        catch(const std::bad_cast& e)
        {
            std::cout << "the type of the object is C!" << std::endl;
        }
    }
    
}

int main()
{
    {
        Base *base;
        base = generate();
        identify(base);
        identify(*base);
        delete base;
    }
    return 0;
}