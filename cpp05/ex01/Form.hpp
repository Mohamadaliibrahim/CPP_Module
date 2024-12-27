#ifndef FORM_HPP
#define FORM_HPP

#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form 
{
    private:
        const std::string name;
        bool              is_signed;
        const int         gradeToSign;
        const int         gradeToExecute;
    public:
        Form();
        Form(Form const & other);
        Form& operator=(const Form& other);
        ~Form();
        Form(std::string name, int gts, int gte);

    const std::string &getName() const;
    bool        getIsSigned() const;
    int         getGradeToSign() const;
    int         getGradeToExecute() const;

    void beSigned(Bureaucrat const &bureaucrat);

    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
};

std::ostream & operator<<(std::ostream & out, Form const & form);

#endif