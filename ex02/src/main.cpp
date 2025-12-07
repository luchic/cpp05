/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 12:22:35 by nluchini          #+#    #+#             */
/*   Updated: 2025/12/07 17:28:28 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.h"
#include "../includes/RobotomyRequestForm.h"
#include "../includes/ShrubberyCreationForm.h"
#include "../includes/PresidentialPardonForm.h"
#include <iostream>

void signFromTest(Bureaucrat& br, AForm& form)
{
	try
	{
		br.signForm(form);
	}
	catch(const std::exception& ex)
	{
		std::cerr << ex.what() << '\n';
	}
}

void executeFromTest(Bureaucrat& br, AForm& form)
{
	try
	{
		br.executeForm(form);
	}
	catch(const std::exception& ex)
	{
		std::cerr << ex.what() << '\n';
	}
}

void testShrubberyCreationForm()
{
	ShrubberyCreationForm form("HomeShrubbery");
	Bureaucrat br("John", 140);
	std::cout << br.getName() << std::endl;	
	signFromTest(br, form);
	executeFromTest(br, form);
	
	ShrubberyCreationForm form2("OfficeShrubbery", "OfficeGarden");
	Bureaucrat br2("Denial", 101);
	
	std::cout << br2.getName() << std::endl;	
	signFromTest(br2, form2);
	executeFromTest(br2, form2);
}

void testRobotomyRequestForm()
{
	RobotomyRequestForm form("BenderRobotomy");
	Bureaucrat br("John", 50);
	std::cout << br.getName() << std::endl;	
	signFromTest(br, form);
	executeFromTest(br, form);
}

void testPresidentialPardonForm()
{
	PresidentialPardonForm form("AlicePardon");
	Bureaucrat br("John", 20);
	std::cout << br.getName() << std::endl;	
	signFromTest(br, form);
	executeFromTest(br, form);
}

int main()
{
	std::cout << "----- ShrubberyCreationForm Test -----" << std::endl;
	testShrubberyCreationForm();
	std::cout << "\n----- RobotomyRequestForm Test -----" <<  std::endl;
	testRobotomyRequestForm();
	std::cout << "\n----- PresidentialPardonForm Test -----" <<  std::endl;
	testPresidentialPardonForm();
	return 0;
	
}