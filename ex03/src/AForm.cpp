/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:47:01 by nluchini          #+#    #+#             */
/*   Updated: 2025/12/07 17:29:16 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.h"
#include <iostream>

AForm::AForm() :
	_name("noname"),
	_isSigned(false),
	_gradeToSign(1),
	_gradeToExecute(1)
{
}

AForm::AForm(const AForm& other) :
	_name(other._name),
	_isSigned(other._isSigned),
	_gradeToSign(other._gradeToSign),
	_gradeToExecute(other._gradeToExecute)
{
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) :
	_name(name),
	_isSigned(false),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::~AForm()
{
}

std::string AForm::getName() const
{
	return _name;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

std::ostream& operator<<(std::ostream& os,
	const AForm& form)
{
	os << "Form " << form.getName();
	return os;
}

void AForm::execute(const Bureaucrat& executor) const
{
	if (!_isSigned)
		throw NotSignFormException();
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
}
