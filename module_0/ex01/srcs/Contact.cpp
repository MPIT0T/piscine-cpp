/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:45:12 by mpitot            #+#    #+#             */
/*   Updated: 2024/06/17 12:59:02 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::getFirstName()
{
	return (firstName);
}
std::string Contact::getLastName()
{
	return (lastName);
}
std::string Contact::getNickName()
{
	return (nickName);
}
std::string Contact::getPhoneNumber()
{
	return (phoneNumber);
}
std::string Contact::getDarkestSecret()
{
	return (darkestSecret);
}

int Contact::setFirstName(std::string arg)
{
	Contact::firstName = arg;
	return (0);
}
int Contact::setLastName(std::string arg)
{
	Contact::lastName = arg;
	return (0);
}
int Contact::setNickName(std::string arg)
{
	Contact::nickName = arg;
	return (0);
}
int Contact::setPhoneNumber(std::string arg)
{
	Contact::phoneNumber = arg;
	return (0);
}
int Contact::setDarkestSecret(std::string arg)
{
	Contact::darkestSecret = arg;
	return (0);
}
