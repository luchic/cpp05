/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:48:44 by nluchini          #+#    #+#             */
/*   Updated: 2025/12/07 17:11:34 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ROBOTOMYREQUESTFORM_H__
#define __ROBOTOMYREQUESTFORM_H__

#include "AForm.h"

class RobotomyRequestForm : public AForm
{
private:
	std::string _target;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm& operator= (const RobotomyRequestForm& other);
	~RobotomyRequestForm();

	RobotomyRequestForm(const std::string& name);
	RobotomyRequestForm(const std::string& name, const std::string& target);

	void execute(const Bureaucrat& executor) const override;
};



#endif