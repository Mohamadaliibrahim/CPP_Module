#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat bob("Bob", 2);
        std::cout << bob << std::endl;

        bob.incrementGrade();
        std::cout << "After increment: " << bob << std::endl;

        bob.incrementGrade(); // This should throw GradeTooHighException
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "-----------------------------" << std::endl;

    try
    {
        Bureaucrat alice("Alice", 149);
        std::cout << alice << std::endl;

        alice.decrementGrade();
        std::cout << "After decrement: " << alice << std::endl;

        alice.decrementGrade(); // This should throw GradeTooLowException
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "-----------------------------" << std::endl;

    try
    {
        Bureaucrat invalidHigh("InvalidHigh", 0); // Should throw GradeTooHighException
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception caught while creating InvalidHigh: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat invalidLow("InvalidLow", 151); // Should throw GradeTooLowException
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception caught while creating InvalidLow: " << e.what() << std::endl;
    }

    return 0;
}
