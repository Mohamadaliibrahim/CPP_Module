#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& n, int gts, int gte)
    : name(n), isSigned(false), gradeToSign(gts), gradeToExecute(gte)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other) :  name(other.name)
    , isSigned(other.isSigned), gradeToSign(other.gradeToSign)
    , gradeToExecute(other.gradeToExecute)
{

}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        isSigned = other.isSigned;
    }
    return *this;
}

AForm::AForm() : name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(1)
{
    std::cout<<"Default constructor called"<< std::endl;
}

AForm::~AForm()
{
    std::cout<<"Destructor called"<< std::endl;
}

const std::string& AForm::getName() const
{
    return (name);
}

bool AForm::getIsSigned() const
{
    return (isSigned);
}

int AForm::getGradeToSign() const
{
    return (gradeToSign);
}

int AForm::getGradeToExecute() const
{
    return (gradeToExecute);
}

void    AForm::beSigned(const Bureaucrat& b)
{
    if (b.get_grade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

void    AForm::execute(const Bureaucrat& e) const
{
    if (!isSigned)
        throw FormNotSignedException();
    if (e.get_grade() > gradeToExecute)
        throw GradeTooLowException();
    executeAction();
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed!";
}