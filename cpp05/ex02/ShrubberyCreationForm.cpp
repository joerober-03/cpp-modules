#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), target("default")
{
    //std::cout << "default ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
    //std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &rhs) : AForm("ShrubberyCreationForm", 145, 137), target(rhs.target)
{
    //std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
    *this = rhs;
}

ShrubberyCreationForm  &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
    //std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
    this->setIsSigned(rhs.getIsSigned());
    return(*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    //std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void    ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    (void)executor;

    std::string fileName = this->target + "_shrubbery";
    std::ofstream newFile;
    newFile.open(fileName);
    if (newFile.fail())
    {
         std::cout << "the file " << fileName << " could not open" << std::endl;
    }
    else
    {
        newFile << 
"               ,@@@@@@@," << std::endl <<
"       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl <<
"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl <<
"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl <<
"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl <<
"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl <<
"   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl <<
"       |o|        | |         | |" << std::endl <<
"       |.|        | |         | |" << std::endl <<
"    \\/ ._|//_/___/  ,|_//__\\/.|_//__/_";
        newFile.close();
    }
}