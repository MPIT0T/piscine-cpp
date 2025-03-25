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

int main()
{
	try
	{
		// Valid Bureaucrats
		Bureaucrat b1("Alice", 1);
		Bureaucrat b2("Bob", 150);
		Bureaucrat b3("Charlie", 75);

		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		std::cout << b3 << std::endl;

		try // Testing increment (should throw for b1)
		{
			std::cout << "Incrementing Alice's grade..." << std::endl;
			b1.incrementGrade(); // Should throw GradeTooHighException
		}
		catch (const std::exception &e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}

		try // Testing decrement (should throw for b2)
		{
			std::cout << "Decrementing Bob's grade..." << std::endl;
			b2.decrementGrade(); // Should throw GradeTooLowException
		}
		catch (const std::exception &e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}

		// Normal increment and decrement
		std::cout << "Incrementing Charlie's grade..." << std::endl;
		b3.incrementGrade();
		std::cout << b3 << std::endl;

		std::cout << "Decrementing Charlie's grade..." << std::endl;
		b3.decrementGrade();
		std::cout << b3 << std::endl;

		// Invalid Bureaucrat creation (should throw exceptions)
		try
		{
			Bureaucrat b4("David", 0); // Too high
		}
		catch (const std::exception &e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}

		try
		{
			Bureaucrat b5("Eve", 151); // Too low
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
