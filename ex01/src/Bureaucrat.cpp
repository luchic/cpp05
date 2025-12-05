/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 21:28:35 by nluchini          #+#    #+#             */
/*   Updated: 2025/12/05 11:07:02 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.h"
#include "../includes/Form.h"
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

void Bureaucrat::signForm(class Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (const Form::GradeTooLowException& e)
	{
		_printCantSignMessage(form, e.what());
	}
	catch (const Form::GradeTooHighException& e)
	{
		_printCantSignMessage(form, e.what());
	}
}

void Bureaucrat::_printCantSignMessage(const Form& form,
	const std::string &reason)
{
	std::cout << _name << " couldn't sign " << form.getName()
			<< " because " << reason << std::endl;
}

std::ostream& operator<<(std::ostream& os,
	const Bureaucrat& bureacrat)
{
	os << bureacrat.getName() << ", bureaucrat grade "
		<< bureacrat.getGrade() << ".";
	return os;
}
