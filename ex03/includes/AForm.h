/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:41:22 by nluchini          #+#    #+#             */
/*   Updated: 2025/12/07 17:45:07 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FORM_HPP
#define __FORM_HPP

#include <string>

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExecute;

public:
	AForm();
	AForm(const AForm& other);
	AForm& operator= (const AForm& other);
	virtual ~AForm();

	AForm(std::string name, int gradeToSign, int gradeToExecute);

	void beSigned(const Bureaucrat& bureaucrat);
	std::string getName() const;
	virtual void execute(const Bureaucrat& executor) const = 0;

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

	class NotSignFormException : public std::exception
	{
	public:
		const char* what() const noexcept override {
			return "Form is not signed";
		}
	};
};

std::ostream& operator<<(std::ostream& os,
	const AForm& form);

#endif