#include "Contact.hpp"

void    Contact::InitializeContact2(void)
{
    while (1)
    {
        std::cout << "Please enter your first name: " << std::endl;
        std::getline(std::cin, FirstName);
        if (!FirstName.empty())
            break;
    }
    while (1)
    {
        std::cout << "Please enter your last name: " << std::endl;
        std::getline(std::cin, LastName);
        if(!LastName.empty())
            break;
    }
    while (1)
    {
        std::cout << "Please enter your Nickname: " << std::endl;
        std::getline(std::cin, Nickname);
        if (!Nickname.empty())
            break;
    }
    while (1)
    {
        int i = -1;
        std::cout << "Please enter your phone number: " << std::endl;
        std::getline(std::cin, PhoneNumber);
        if (!PhoneNumber.empty())
        {
            int trigger = 0;
            while (PhoneNumber[++i] != 0)
            {
                if (PhoneNumber[i] > 57 || PhoneNumber[i] < 48)
                {
                    trigger++;
                    std::cout << "please only enter numbers for phone number" << std::endl;
                    break;
                }
            }
            if (trigger == 0)
                break;
        }
    }
    while (1)
    {
        std::cout << "Please enter your darkest secret: " << std::endl;
        std::getline(std::cin, DarkestSecret);
        if(!PhoneNumber.empty())
            break;
    }
}

std::string    Contact::ftTruncate(std::string str)
{
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    return (str);
}

void   Contact::DisplayContact2(int tracker, int index)
{
    if (index < tracker)
    {
        std::cout << "first name:     " << FirstName << std::endl;
        std::cout << "last name:      " << LastName << std::endl;
        std::cout << "nickname:       " << Nickname << std::endl;
        std::cout << "phone number:   " << PhoneNumber << std::endl;
        std::cout << "darkest secret: " << DarkestSecret << std::endl;
    }
    else
        std::cout << "invalid index" << std::endl;
}

void    Contact::DisplayListContacts2(int tracker, int index)
{    
    if (index < tracker)
    {
        std::cout << "|" << std::setw(10) << index << "|"
                         << std::setw(10) << ftTruncate(FirstName) << "|"
                         << std::setw(10) << ftTruncate(LastName) << "|"
                         << std::setw(10) << ftTruncate(Nickname) << "|"
                         << std::endl;
    }
}