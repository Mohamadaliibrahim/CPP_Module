#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool    isSigned;
        const int gradeToSign;
        const int gradeToExecute;
    
    protected:
        virtual void executeAction() const = 0;
    
    public:
        AForm();
        AForm(const std::string& n, int gts, int gte);
        AForm(const AForm& other);
        virtual ~AForm();
        AForm& operator=(const AForm& other);

        const std::string& getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void    beSigned(const Bureaucrat& b);
        void    execute(const Bureaucrat& e) const;

        class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class FormNotSignedException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

};

#endif