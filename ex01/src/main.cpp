/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 12:22:35 by nluchini          #+#    #+#             */
/*   Updated: 2025/12/05 11:06:39 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.h"
#include "../includes/Form.h"
#include <iostream>

int main()
{
	
	try
	{
		Form form("TopSecret", 5, 10);
		Bureaucrat br("John", 2);
		Bureaucrat br2("Doe", 20);
		std::cout << br.getName() << std::endl;	
		br.signForm(form);
		br2.signForm(form);
	}
	catch(const std::exception& ex)
	{
		std::cerr << ex.what() << '\n';
	}
	return 0;
}