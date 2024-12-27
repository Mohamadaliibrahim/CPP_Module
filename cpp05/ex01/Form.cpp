#include "Form.hpp"

Form::Form() : name("Default Form"), is_signed(false), gradeToSign(150), gradeToExecute(150)
{

}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        this->is_signed = other.is_signed;
    }
    return (*this);
}

Form::~Form()
{
    std::cout << "Form Destructor Called" << std::endl;
}

Form::Form(Form const & other) : name(other.name),is_signed(other.is_signed), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{

}

Form::Form(std::string n, int gts, int gte) : name(n), is_signed(false), gradeToSign(gts), gradeToExecute(gte)
{
    if (gts < 1 || gte < 1)
        throw Form::GradeTooHighException();
    if (gts > 150 || gte > 150)
        throw Form::GradeTooLowException();
}

const std::string& Form::getName() const
{
    return (name);
}

bool Form::getIsSigned() const
{
    return (is_signed);
}

int Form::getGradeToSign() const
{
    return (gradeToSign);
}

int Form::getGradeToExecute() const
{
    return (gradeToExecute);
}

void    Form::beSigned(Bureaucrat const &bureaucrat)
{
    if (bureaucrat.get_grade() <= gradeToSign)
        is_signed = true;
    else
        throw Form::GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form: grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form: grade is too low";
}

std::ostream & operator<<(std::ostream & out, Form const & form)
{
    out << "Form name: "<< form.getName()
        << ", is signed: " << (form.getIsSigned() ? "true" : "false")
        << ", grade to sign: " << form.getGradeToSign()
        << ", grade to execute: " << form.getGradeToExecute();
    return (out);
}