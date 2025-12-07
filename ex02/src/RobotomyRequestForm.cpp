/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:12:55 by nluchini          #+#    #+#             */
/*   Updated: 2025/12/07 17:10:17 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.h"
#include <iostream>
#include <random>

RobotomyRequestForm::RobotomyRequestForm() :
	AForm("RobotomyRequestForm", 72, 45)
{
	_target = "default_target";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
	AForm(other)
{
	_target = other._target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& name) :
	AForm(name, 72, 45)
{
	_target = "default_target";
}

RobotomyRequestForm::RobotomyRequestForm(
	const std::string& name, const std::string& target) :
	AForm(name, 72, 45)
{
	_target = target;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	AForm::execute(executor);

	std::random_device rd;
	std::default_random_engine gen(rd());
	std::uniform_int_distribution<int> dist(0, 1);

	std::cout << "Bzzzzzz... Vrrrrrrr... ";
	if (dist(gen))
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "The robotomy failed on " << _target << "." << std::endl;
}
