#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("Default")
{
    std::cout<<"RobotomyRequestForm Default constructor called"<< std::endl;
    std::srand(std::time(0));
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& t) : AForm("RobotomyRequestForm", 72, 45), target(t)
{
    std::cout<<"RobotomyRequestForm Parameterized constructor called"<<std::endl;
    std::srand(std::time(0));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.target)
{
    std::cout<<"RobotomyRequestForm copy constructor called"<< std::endl;
    std::srand(std::time(0));
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout<< "RobotomyRequestForm Destructor called"<< std::endl;
}

void RobotomyRequestForm::executeAction() const
{
    std::cout << "Drilling noises..." << std::endl;
    if (std::rand() % 2)
    {
        std::cout << target << " has been robotomized successfully!" << std::endl;
    }
    else
    {
        std::cout << "Robotomy failed on " << target << "." << std::endl;
    }
}

