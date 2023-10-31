#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    {
        std::cout << std::endl << "EX00 TESTS" << std::endl;
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); //will output the cat sound!
        j->makeSound();
        meta->makeSound();

        delete meta;
        delete j;
        delete i;
    }
    std::cout << std::endl;
    {
        const WrongAnimal* meta = new WrongAnimal();
        const WrongAnimal* i = new WrongCat();
        std::cout << i->getType() << " " << std::endl;
        i->makeSound();
        meta->makeSound();

        delete meta;
        delete i;
    }
    std::cout << std::endl;
    {
        std::cout << "EX01 TESTS" << std::endl;
        Animal *animals[] =
        {
            new Cat(),
            new Cat(),
            new Dog(),
            new Dog()
        };
        Dog copy(*(Dog *)animals[2]);
		for (int i = 0; i < 10; i++)
		{
			std::cout << copy.getBrain()->getIdea(i) << std::endl;
			std::cout << ((Dog *)animals[2])->getBrain()->getIdea(i) << std::endl;
		}
        //delete copy;
        for (int i = 0; i < 4; i++)
            delete animals[i];
    }
    return 0;
}