/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:49:12 by nluchini          #+#    #+#             */
/*   Updated: 2025/12/07 17:11:39 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SHRUBBERYCREATIONFORM_H__
#define __SHRUBBERYCREATIONFORM_H__

#include "AForm.h"

class ShrubberyCreationForm : public AForm
{
private:
	std::string _target;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm& operator= (const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();

	ShrubberyCreationForm(const std::string& name);
	ShrubberyCreationForm(const std::string& name, const std::string& target);

	void execute(const Bureaucrat& executor) const override;
};

#endif