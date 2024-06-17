/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:31:35 by mpitot            #+#    #+#             */
/*   Updated: 2024/06/17 14:45:19 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	first = -1;
	full = false;
}


int	PhoneBook::addContact(std::string &fName, std::string &lName, std::string &nName, std::string &phone, std::string &secret)
{
	if (fName.empty() || lName.empty() || nName.empty() || phone.empty() || secret.empty())
		std::cerr << "No fields can be left emptpy." << std::endl;


	return (0);
}
