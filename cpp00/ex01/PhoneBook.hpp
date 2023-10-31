#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
    private :

    Contact contact[8];

    public:

    void    InitializeContact1(int index);
    void    DisplayListContacts1(int tracker);
    void    DisplayContact1(std::string index, int tracker);
};

#endif