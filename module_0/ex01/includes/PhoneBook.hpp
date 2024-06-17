/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:12:14 by mpitot            #+#    #+#             */
/*   Updated: 2024/06/17 14:45:19 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
private:
	Contact	contacts[8];
	int		first;
	bool	full;

public:
	PhoneBook();

	int	addContact(std::string &fName, std::string &lName, std::string &nName, std::string &phone, std::string &secret);
};