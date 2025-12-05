/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 21:27:43 by nluchini          #+#    #+#             */
/*   Updated: 2025/12/05 10:56:43 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT_HPP
#define __BUREAUCRAT_HPP

#include "Form.h"
#include <string>

class Bureaucrat
{

private:
	const std::string _name;
	int _grade;
	void _printCantSignMessage(const Form& form, const std::string &reason);

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

	void signForm(class Form& form);

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