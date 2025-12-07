/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 21:28:35 by nluchini          #+#    #+#             */
/*   Updated: 2025/12/07 16:50:02 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.h"
#include "../includes/AForm.h"
#include <iostream>

Bureaucrat::Bureaucrat() :
	_name("noname"),
	_grade(1)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) :
	Bureaucrat(other._name, other._grade)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		_grade = other._grade;
	return *this;
}

Bureaucrat::Bureaucrat(std::string name, int grade) :
	_name(name),
	_grade(grade)
{
	if (grade < 1)
		throw GradeTooLowException();
	if (grade > 150)
		throw GradeTooHighException();
}

Bureaucrat::~Bureaucrat()
{
}

std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrimentGrade()
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(class AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (const AForm::GradeTooLowException& e)
	{
		_printCantSignMessage(form, e.what());
	}
	catch (const AForm::GradeTooHighException& e)
	{
		_printCantSignMessage(form, e.what());
	}
}

void Bureaucrat::_printCantSignMessage(const AForm& form,
	const std::string &reason)
{
	std::cout << _name << " couldn't sign " << form.getName()
			<< " because " << reason << std::endl;
}

void Bureaucrat::_printCantExecuteMessage(const AForm& form,
	const std::string &reason)
{
		std::cout << _name << " couldn't execute " << form.getName()
			<< " because " << reason << std::endl;
}
	
void Bureaucrat::executeForm(class AForm& form)
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (const AForm::GradeTooLowException& e)
	{
		_printCantExecuteMessage(form, e.what());
	}
	catch (const AForm::GradeTooHighException& e)
	{
		_printCantExecuteMessage(form, e.what());
	}
}

std::ostream& operator<<(std::ostream& os,
	const Bureaucrat& bureacrat)
{
	os << bureacrat.getName() << ", bureaucrat grade "
		<< bureacrat.getGrade() << ".";
	return os;
}
