#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

typedef AForm* (*FormCreator)(const std::string& target);

AForm* createShrubbery(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

AForm* createRobotomy(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

AForm* createPresidentialPardon(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

Intern::Intern()
{
    std::cout<<"Intern Default constructor called"<< std::endl;
}

Intern::Intern(const Intern& other)
{
    std::cout<<"Intern Copy constructor called"<< std::endl;
    (void)other;
}

Intern& Intern::operator=(const Intern& other)
{
    std::cout<<"Intern Copy operator called"<< std::endl;
    (void)other;
    return *this;
}

Intern::~Intern()
{
    std::cout<<"Intern Destructor called"<< std::endl;
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
    struct FormPair
    {
        std::string name;
        FormCreator creator;
    };

    FormPair forms[] =
    {
        { "shrubbery creation", &createShrubbery },
        { "robotomy request", &createRobotomy },
        { "presidential pardon", &createPresidentialPardon }
    };

    const int numForms = sizeof(forms) / sizeof(forms[0]);

    for (int i = 0; i < numForms; i++)
    {
        if (forms[i].name == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i].creator(target);
        }
    }

    std::cout << "Intern cannot create " << formName << " because it does not exist." << std::endl;
    return NULL;
}
