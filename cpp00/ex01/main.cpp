#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
    std::string input;
    PhoneBook phonebook;
    int index = 1;
    int tracker = 1;
    std::string toDisplay;

    while (1)
    {
        std::cout << "please enter a valid command: ";
        std::getline(std::cin, input);
        if (input.compare("ADD") == 0)
        {
            phonebook.InitializeContact1(index);
            index++;
            tracker++;
            if (index > 8)
                index = 1;
        }
        else if (input.compare("SEARCH") == 0)
        {
            phonebook.DisplayListContacts1(tracker);
            if (tracker > 1)
            {
                std::cout << "please choose the contact to display: " << std::endl;
                std::getline(std::cin, toDisplay);
                phonebook.DisplayContact1(toDisplay, tracker);
            }
        }
        else if (input.compare("EXIT") == 0)
        {
            std::cout << "goodbye !" << std::endl;
            return(0);
        }
        else
            std::cout << "invalid command" << std::endl;
    }
    return(0);
}