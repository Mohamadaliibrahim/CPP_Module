#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"
#include <string>
#include <exception>

class AForm;

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();
        Bureaucrat(const std::string n, int g);

        const std::string& get_name() const;
        int     get_grade() const;

        void    incrementGrade();
        void    decrementGrade();
        void    signForm(AForm &form) const;
        void executeForm(const AForm& form) const;
        
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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif