/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 21:27:43 by nluchini          #+#    #+#             */
/*   Updated: 2025/12/05 11:47:56 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT_HPP
#define __BUREAUCRAT_HPP

#include "AForm.h"
#include <string>

class Bureaucrat
{

private:
	const std::string _name;
	int _grade;
	void _printCantSignMessage(const AForm& form, const std::string &reason);
	void _printCantExecuteMessage(const AForm& form, const std::string &reason);

public:
	
	Bureaucrat();
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator= (const Bureaucrat& other);
	~Bureaucrat();

	Bureaucrat(std::string name, int grade);

	std::string getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrimentGrade();

	void signForm(class AForm& form);
	void executeForm(class AForm& form);

	class GradeTooHighException : public std::exception
	{
	public:
		const char* what() const noexcept override {
			return "Bureaucat grade is too high";
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const noexcept override {
			return "Bureaucat grade is too low";
		}
	};
};

std::ostream& operator<<(std::ostream& os,
	const Bureaucrat& bureacrat);

#endif