/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamibr <mohamibr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 10:00:00 by assistant         #+#    #+#             */
/*   Updated: 2024/12/27 22:36:42 by mohamibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
    srand(time(NULL));

    std::cout << "\033[33m" << std::endl << "=== Intern Test Start ===" << "\033[0m" << std::endl;

    Intern someRandomIntern;

    AForm* form1 = someRandomIntern.makeForm("shrubbery creation", "Home");
    AForm* form2 = someRandomIntern.makeForm("robotomy request", "Bender");
    AForm* form3 = someRandomIntern.makeForm("presidential pardon", "Arthur");
    AForm* form4 = someRandomIntern.makeForm("unknown form", "Target");

    std::cout << std::endl;

    Bureaucrat gardener("Gardener", 140);
    Bureaucrat technician("Technician", 50);
    Bureaucrat president("President", 5);
    Bureaucrat lowRank("LowRank", 150);

    std::cout << "\033[33m" << std::endl << "=== Signing Forms ===" << "\033[0m" << std::endl;

    if (form1)
        gardener.signForm(*form1);
    if (form2)
        technician.signForm(*form2);
    if (form3)
        president.signForm(*form3);
    if (form4)
        lowRank.signForm(*form4);

    std::cout << std::endl;

    std::cout << "\033[33m" << std::endl << "=== Executing Forms ===" << "\033[0m" << std::endl;

    if (form1)
        gardener.executeForm(*form1);
    if (form2)
        technician.executeForm(*form2);
    if (form3)
        president.executeForm(*form3);
    if (form4)
        lowRank.executeForm(*form4);
    std::cout << "\033[33m" << std::endl << "=== Memory Cleanup ===" << "\033[0m" << std::endl;

    delete form1;
    delete form2;
    delete form3;
    delete form4;

    std::cout << "\033[33m" << std::endl << "=== Intern Test End ===" << "\033[0m" << std::endl;

    return 0;
}
