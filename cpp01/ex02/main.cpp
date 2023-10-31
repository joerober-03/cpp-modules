#include <iostream>

int main()
{
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string &stringREF = string;

    std::cout << "           addresses      |  values" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "string:    " << &string << " | " << string << std::endl;
    std::cout << "stringPTR: " << stringPTR << " | " << *stringPTR << std::endl;
    std::cout << "stringREF: " << &stringREF << " | " << stringREF << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
}