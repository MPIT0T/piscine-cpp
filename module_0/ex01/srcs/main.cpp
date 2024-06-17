/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:00:35 by mpitot            #+#    #+#             */
/*   Updated: 2024/06/17 15:44:36 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int	addContact(PhoneBook phone_book)
{
	std::string fName;
	std::string lName;
	std::string nName;
	std::string phone;
	std::string dSecret;

	while (42)
	{
		std::cout << "First Name : ";
		std::getline(std::cin, fName);
		if (std::cin.eof())
			exit(0);
		if (fName.empty())
			std::cout << "Field cannot be empty" << std::endl;
		else
			break ;
	}

	while (42)
	{
		std::cout << "Last Name : ";
		std::getline(std::cin, lName);
		if (std::cin.eof())
			exit(0);
		if (lName.empty())
			std::cout << "Field cannot be empty" << std::endl;
		else
			break ;
	}

	while (42)
	{
		std::cout << "Nickname : ";
		std::getline(std::cin, nName);
		if (std::cin.eof())
			exit(0);
		if (nName.empty())
			std::cout << "Field cannot be empty" << std::endl;
		else
			break ;
	}

	while (42)
	{
		std::cout << "Phone Number : ";
		std::getline(std::cin, phone);
		if (std::cin.eof())
			exit(0);
		if (phone.empty())
			std::cout << "Field cannot be empty" << std::endl;
		else
			break ;
	}

	while (42)
	{
		std::cout << "Darkest Secret : ";
		std::getline(std::cin, dSecret);
		if (std::cin.eof())
			exit(0);
		if (dSecret.empty())
			std::cout << "Field cannot be empty" << std::endl;
		else
			break ;
	}
	phone_book.addContact(fName, lName, nName, phone, dSecret);
	return (0);
}

int	main()
{
	PhoneBook	phone_book;
	std::string line;

	while (42)
	{
		std::getline(std::cin, line);
		if (std::cin.eof())
			break ;
		if (line.compare("ADD") == 0)
			addContact(phone_book);
		if (line.compare("SEARCH") == 0)
			std::cout << "SEARCH" << std::endl;
		if (line.compare("EXIT") == 0)
			break ;
	}
}
