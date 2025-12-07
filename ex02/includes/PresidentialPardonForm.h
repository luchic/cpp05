/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:28:18 by nluchini          #+#    #+#             */
/*   Updated: 2025/12/07 17:11:29 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PRESIDENTIALPARDONFORM_H__
#define __PRESIDENTIALPARDONFORM_H__

#include "AForm.h"

class PresidentialPardonForm : public AForm
{
private:
	std::string _target;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm& operator= (const PresidentialPardonForm& other);
	~PresidentialPardonForm();

	PresidentialPardonForm(const std::string& name);
	PresidentialPardonForm(const std::string& name, const std::string& target);
	void execute(const Bureaucrat& executor) const override;
};

#endif