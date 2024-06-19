/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:00:35 by mpitot            #+#    #+#             */
/*   Updated: 2024/06/19 15:21:59 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

void	putContact(Contact *contact)
{
	std::cout << "First Name : " << contact->getFirstName() << std::endl;
	std::cout << "Last Name : " << contact->getLastName() << std::endl;
	std::cout << "Nickname : " << contact->getNickName() << std::endl;
	std::cout << "Phone Number : " << contact->getPhoneNumber() << std::endl;
}

int		addContact(PhoneBook *phone_book)
{
	Contact		contact;
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
	contact.setFirstName(fName);
	contact.setLastName(lName);
	contact.setNickName(nName);
	contact.setPhoneNumber(phone);
	contact.setDarkestSecret(dSecret);
	phone_book->addContact(contact);
	return (0);
}

void	putValue(const std::string& value)
{
	if (value.length() == 10)
		std::cout << value;
	else if (value.length() > 10)
		std::cout << value.substr(0, 9) << ".";
	else
	{
		for (size_t i = 0; i < 10 - value.length(); i++)
			std::cout << " ";
		std::cout << value;
	}
}

int		search(PhoneBook *phone_book)
{
	int			bookSize = phone_book->getContactAmount();
	std::string	line;

	if (bookSize == 0)
	{
		std::cout << "REPERTORY empty..." << std::endl;
		return (0);
	}
		std::cout << "REPERTORY :" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|id________|first_____|last______|nick______|" << std::endl;
	for (int i = 0; i < bookSize; i++)
	{
		std::cout << "|         " << i + 1 << "|";
		putValue(phone_book->getContact(i)->getFirstName());
		std::cout << "|";
		putValue(phone_book->getContact(i)->getLastName());
		std::cout << "|";
		putValue(phone_book->getContact(i)->getNickName());
		std::cout << "|" << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;

	std::cout << std::endl;
	while (42)
	{
		std::cout << "Enter the contact id : ";
		std::getline(std::cin, line);
		if (std::cin.eof())
			exit(0);
		if ((bookSize >= 1 && line == "1")
		 || (bookSize >= 2 && line == "2")
		 || (bookSize >= 3 && line == "3")
		 || (bookSize >= 4 && line == "4")
		 || (bookSize >= 5 && line == "5")
		 || (bookSize >= 6 && line == "6")
		 || (bookSize >= 7 && line == "7")
		 || (bookSize >= 8 && line == "8"))
			break ;
		std::cout << "must be an number displayed in the first column of the tab" << std::endl;
	}
	line == "1" ? putContact(phone_book->getContact(0)) : (void)0;
	line == "2" ? putContact(phone_book->getContact(1)) : (void)0;
	line == "3" ? putContact(phone_book->getContact(2)) : (void)0;
	line == "4" ? putContact(phone_book->getContact(3)) : (void)0;
	line == "5" ? putContact(phone_book->getContact(4)) : (void)0;
	line == "6" ? putContact(phone_book->getContact(5)) : (void)0;
	line == "7" ? putContact(phone_book->getContact(6)) : (void)0;
	line == "8" ? putContact(phone_book->getContact(7)) : (void)0;
	return (0);
}

int		main()
{
	PhoneBook	repertory;
	std::string line;

	while (42)
	{
		std::cout << "Enter a command..." << std::endl;
		std::cout << "[ADD] | [SEARCH] | [EXIT]" << std::endl;
		std::cout << "> ";
		std::getline(std::cin, line);
		if (std::cin.eof())
			exit(0);
		if (line == "ADD")
		{
			std::cout << std::endl;
			addContact(&repertory);
			std::cout << std::endl;
		}
		else if (line == "SEARCH")
		{
			std::cout << std::endl;
			search(&repertory);
			std::cout << std::endl;
		}
		else if (line == "EXIT")
			break ;
		else
			std::cout << std::endl;
	}
	return (0);
}
