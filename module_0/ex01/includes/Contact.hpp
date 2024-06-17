/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:21:04 by mpitot            #+#    #+#             */
/*   Updated: 2024/06/17 14:50:00 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

#ifndef CONTACT_HPP
# define CONTACT_HPP


class Contact
{
private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;

public:
	std::string getFirstName();
	std::string	getLastName();
	std::string	getNickName();
	std::string	getPhoneNumber();
	std::string	getDarkestSecret();

	int	setFirstName(std::string arg);
	int	setLastName(std::string arg);
	int	setNickName(std::string arg);
	int	setPhoneNumber(std::string arg);
	int	setDarkestSecret(std::string arg);
};

#endif