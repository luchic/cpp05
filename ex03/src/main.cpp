/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 12:22:35 by nluchini          #+#    #+#             */
/*   Updated: 2025/12/07 17:44:15 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.h"
#include "../includes/RobotomyRequestForm.h"
#include "../includes/ShrubberyCreationForm.h"
#include "../includes/PresidentialPardonForm.h"
#include "../includes/Intern.h"
#include <iostream>


void testIntern()
{
    std::cout << "----- Intern Test -----" << std::endl;

    Intern intern;

    AForm* f1 = intern.makeForm("shrubbery creation", "home");
    AForm* f2 = intern.makeForm("robotomy request", "Bender");
    AForm* f3 = intern.makeForm("presidential pardon", "Arthur Dent");
    AForm* f4 = intern.makeForm("unknown form", "nobody"); // should fail

    std::cout << std::endl;

    Bureaucrat boss("Boss", 1);

    if (f1) {
        boss.signForm(*f1);
        boss.executeForm(*f1);
        delete f1;
    }
    if (f2) {
        boss.signForm(*f2);
        boss.executeForm(*f2);
        delete f2;
    }
    if (f3) {
        boss.signForm(*f3);
        boss.executeForm(*f3);
        delete f3;
    }
    if (f4) {
        // should be null, but just in case
        delete f4;
    }
}

int main()
{
	testIntern();
	return 0;
	
}