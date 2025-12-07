/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:02:18 by nluchini          #+#    #+#             */
/*   Updated: 2025/12/07 17:24:46 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.h"
#include "../includes/PresidentialPardonForm.h"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() :
	AForm("PresidentialPardonForm", 25, 5)
{
	_target = "default_target";
}

PresidentialPardonForm::PresidentialPardonForm(
	const PresidentialPardonForm& other) :
	AForm(other)
{
	_target = other._target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(
	const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& name) :
	AForm(name, 25, 5)
{
	_target = "default_target";
}

PresidentialPardonForm::PresidentialPardonForm(
	const std::string& name, const std::string& target) :
	AForm(name, 25, 5)
{
	_target = target;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	AForm::execute(executor);
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox."
			  << std::endl;
}