#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
    
    const std::string target;

    public:

    RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm &rhs);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);
    ~RobotomyRequestForm();
    RobotomyRequestForm(const std::string target);

    void execute(Bureaucrat const &executor) const;
};