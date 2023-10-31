#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
    private:

    protected:

    public:

    Cat(void);
    Cat(const Cat &rhs);
    Cat  &operator=(const Cat &rhs);
    ~Cat(void);

    void    makeSound(void) const;
    std::string getType(void) const;
};

#endif