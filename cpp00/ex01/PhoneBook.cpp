#include "PhoneBook.hpp"

void    PhoneBook::InitializeContact1(int index)
{
    contact[index - 1].InitializeContact2();
}

void    PhoneBook::DisplayListContacts1(int tracker)
{
    if (tracker == 1)
        std::cout << "no contacts added yet" << std::endl;
    else
    {
        std::cout << std::endl << std::endl;
        std::cout << "---------------------------------------------" << std::endl;
        std::cout << "|" << std::setw(10) << "index" << "|"
                         << std::setw(10) << "first name" << "|"
                         << std::setw(10) << "last name" << "|"
                         << std::setw(10) << "nickname" << "|" << std::endl;
        std::cout << "|----------|----------|----------|----------|" << std::endl;
        for (int i = 0; i < 8; i++)
            contact[i].DisplayListContacts2(tracker, i + 1);
        std::cout << "---------------------------------------------"
                  << std::endl << std::endl << std::endl;
    }
}

void    PhoneBook::DisplayContact1(std::string index, int tracker)
{
    if (index.compare("1") == 0)
        contact[0].DisplayContact2(tracker, 1);
    else if (index.compare("2") == 0)
        contact[1].DisplayContact2(tracker, 2);
    else if (index.compare("3") == 0)
        contact[2].DisplayContact2(tracker, 3);
    else if (index.compare("4") == 0)
        contact[3].DisplayContact2(tracker, 4);
    else if (index.compare("5") == 0)
        contact[4].DisplayContact2(tracker, 5);
    else if (index.compare("6") == 0)
        contact[5].DisplayContact2(tracker, 6);
    else if (index.compare("7") == 0)
        contact[6].DisplayContact2(tracker, 7);
    else if (index.compare("8") == 0)
        contact[7].DisplayContact2(tracker, 8);
    else
        std::cout << "invalid index" << std::endl;
}
    