/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:41:22 by nluchini          #+#    #+#             */
/*   Updated: 2025/12/05 11:15:31 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FORM_HPP
#define __FORM_HPP

#include <string>

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExecute;
	/* data */
public:
	Form();
	Form(const Form& other);
	Form& operator= (const Form& other);
	~Form();

	Form(std::string name, int gradeToSign, int gradeToExecute);

	void beSigned(const Bureaucrat& bureaucrat);
	std::string getName() const;

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
	const Form& form);

#endif