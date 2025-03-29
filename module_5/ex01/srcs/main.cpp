/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:44:04 by mpitot            #+#    #+#             */
/*   Updated: 2024/10/13 22:43:37 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		// Valid Bureaucrats
		Bureaucrat alice("Alice", 1);
		Bureaucrat bob("Bob", 50);
		Bureaucrat charlie("Charlie", 150);

		// Valid Forms
		Form formA("Form A", 100, 50);
		Form formB("Form B", 1, 1);
		Form formC("Form C", 150, 150);

		std::cout << formA << std::endl;
		std::cout << formB << std::endl;
		std::cout << formC << std::endl;

		// Trying to sign forms
		std::cout << "\nBob attempts to sign Form A:" << std::endl;
		bob.signForm(formA); // Should succeed

		std::cout << "\nCharlie attempts to sign Form A:" << std::endl;
		charlie.signForm(formA); // Should fail (grade too low)

		std::cout << "\nAlice attempts to sign Form B:" << std::endl;
		alice.signForm(formB); // Should succeed

		std::cout << "\nBob attempts to sign Form B:" << std::endl;
		bob.signForm(formB); // Should fail (grade too low)

		std::cout << "\nCharlie attempts to sign Form C:" << std::endl;
		charlie.signForm(formC); // Should succeed


		try // Invalid Form (Should throw an exception)
		{
			Form invalidForm("Invalid", 0, 50); // Grade too high
		}
		catch (const std::exception &e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}

		try
		{
			Form invalidForm("Invalid", 151, 50); // Grade too low
		}
		catch (const std::exception &e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}

	}
	catch (const std::exception &e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}

	return 0;
}
