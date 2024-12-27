#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150)
{
}

Bureaucrat::~Bureaucrat()
{
    std::cout<<"Bureaucrat Destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string n, int g) : name(n)
{
    if (g < 1)
        throw GradeTooHighException();
    if (g > 150)
        throw GradeTooLowException();
    grade = g;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade)
{
}

int Bureaucrat::get_grade() const
{
    return (grade);
}

const std::string& Bureaucrat::get_name() const
{
    return (name);
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        this->grade = other.grade;
    }
    return (*this);
}

void    Bureaucrat::incrementGrade()
{
    if (grade -1 < 1)
        throw GradeTooHighException();
    grade--;
}

void    Bureaucrat::decrementGrade()
{
    if (grade + 1 > 150)
        throw GradeTooLowException();
    grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

void    Bureaucrat::signForm(AForm &form) const
{
    try
    {
        form.beSigned(*this);
        std::cout<< this->get_name() << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << this->get_name() << " couldn't sign "<< form.getName()
            << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    os << bureaucrat.get_name() << ", bureaucrat grade " << bureaucrat.get_grade() << ".";
    return os;
}

void Bureaucrat::executeForm(const AForm& form) const
{
    try
    {
        form.execute(*this);
        std::cout << this->get_name() << " executed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << this->get_name() << " couldn't execute " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

