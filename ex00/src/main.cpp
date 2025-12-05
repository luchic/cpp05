/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 12:22:35 by nluchini          #+#    #+#             */
/*   Updated: 2025/12/05 10:37:57 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.h"
#include <iostream>

void tooHighTest()
{
	try
	{
		Bureaucrat br("John", 210);
		std::cout << br.getName() << std::endl;	
	
	}
	catch(const Bureaucrat::GradeTooHighException& ex)
	{
		std::cerr << ex.what() << '\n';
	}	
}

void tooLowTest()
{
	try
	{
		Bureaucrat br("John", -10);
		std::cout << br.getName() << std::endl;	
	
	}
	catch(const Bureaucrat::GradeTooLowException& ex)
	{
		std::cerr << ex.what() << '\n';
	}	
}

int main()
{
	
	try
	{
		Bureaucrat br("John", 2);
		std::cout << br.getName() << std::endl;	
	
	}
	catch(const std::exception& ex)
	{
		std::cerr << ex.what() << '\n';
	}	
	tooHighTest();
	tooLowTest();
	return 0;
}