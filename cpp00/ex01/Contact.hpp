#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact
{
    private:

    std::string FirstName;
    std::string LastName;
    std::string Nickname;
    std::string PhoneNumber;
    std::string DarkestSecret;

    std::string    ftTruncate(std::string str);

    public:

    void    InitializeContact2(void);
    void    DisplayContact2(int tracker, int index);
    void    DisplayListContacts2(int tracker, int index);
};

#endif