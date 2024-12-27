#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
    private:
        const std::string target;

    protected:
        void    executeAction() const ;
    
    public:
    RobotomyRequestForm();
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    RobotomyRequestForm(const std::string& t);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    virtual ~RobotomyRequestForm();
};

#endif