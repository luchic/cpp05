/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 21:28:35 by nluchini          #+#    #+#             */
/*   Updated: 2025/12/05 10:45:30 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.h"
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
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
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

std::ostream& operator<<(std::ostream& os,
	const Bureaucrat& bureacrat)
{
	os << bureacrat.getName() << ", bureaucrat grade "
		<< bureacrat.getGrade() << ".";
	return os;
}
