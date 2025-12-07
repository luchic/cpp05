/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:11:22 by nluchini          #+#    #+#             */
/*   Updated: 2025/12/07 17:24:15 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.h"
#include <random>
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("ShrubberyCreationForm", 145, 137)
{
	_target = "default_target";
}

ShrubberyCreationForm::ShrubberyCreationForm(
	const ShrubberyCreationForm& other) :
	AForm(other)
{
	_target = other._target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
	const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& name) :
	AForm(name, 145, 137)
{
	_target = "default_target";
}

ShrubberyCreationForm::ShrubberyCreationForm(
	const std::string& name, const std::string& target) :
	AForm(name, 145, 137)
{
	_target = target;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	AForm::execute(executor);
	
	std::ofstream out((_target + "_shrubbery").c_str());
    if (!out.is_open())
        throw std::runtime_error("Failed to open shrubbery file");

    out << "       _-_        \n"
           "    /~~   ~~\\    \n"
           " /~~         ~~\\ \n"
           "{               }\n"
           " \\  _-     -_  / \n"
           "   ~  \\\\ //  ~  \n"
           "_- -   | | _- _  \n"
           "  _ -  | |   -_  \n"
           "      // \\\\      \n";

    out.close();
}