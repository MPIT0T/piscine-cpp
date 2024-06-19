/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:31:35 by mpitot            #+#    #+#             */
/*   Updated: 2024/06/19 13:34:04 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#include <utility>

PhoneBook::PhoneBook()
{
	index = 0;
	amount = 0;
}


int		PhoneBook::addContact(Contact contact)
{
	contacts[index] = contact;
	index = (index + 1) % 8;
	if (amount < 8)
		amount++;
	return (0);
}

int		PhoneBook::getContactAmount()
{
	return (amount);
}

Contact	*PhoneBook::getContact(int i)
{
	return (&contacts[i]);
}