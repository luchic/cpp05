/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:41:23 by nluchini          #+#    #+#             */
/*   Updated: 2025/12/07 17:50:59 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.h"
#include "../includes/ShrubberyCreationForm.h"
#include "../includes/RobotomyRequestForm.h"
#include "../includes/PresidentialPardonForm.h"
#include <iostream>

Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

Intern::~Intern()
{
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    // list of known form names
    const std::string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    // matching creators
    AForm* (*creators[3])(const std::string &n, const std::string&) = {
        [](const std::string &n, const std::string& t)
				-> AForm* { return new ShrubberyCreationForm(n, t); },
        [](const std::string &n, const std::string& t)
				-> AForm* { return new RobotomyRequestForm(n, t); },
        [](const std::string &n, const std::string& t)
				-> AForm* { return new PresidentialPardonForm(n, t); }
    };

    for (int i = 0; i < 3; ++i)
    {
        if (formName == names[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return creators[i](formName, target);
        }
    }

    std::cout << "Intern cannot create form: " << formName << std::endl;
    return nullptr;
}