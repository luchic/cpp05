/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:30:54 by nluchini          #+#    #+#             */
/*   Updated: 2025/12/07 17:38:11 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INTERN_H__
#define __INTERN_H__

#include "AForm.h"

class Intern
{
public:
	Intern();
	Intern(const Intern& other);
	Intern& operator= (const Intern& other);
	~Intern();

	AForm *makeForm(const std::string& formName, const std::string& target);
};


#endif