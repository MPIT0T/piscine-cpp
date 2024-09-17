/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:43:17 by mpitot            #+#    #+#             */
/*   Updated: 2024/09/17 11:02:58 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

const std::string	Harl::levels[] = {
	"DEBUG",
	"INFO",
	"WARNING",
	"ERROR",
};

Harl::Harl(std::string level)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->levels[i] == level)
		{
			this->lvl = i;
			break ;
		}
	}
}

Harl::~Harl() {}

void Harl::debug()
{
	std::cout << "[ DEBUG ]" << std::endl
	<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
	<< std::endl << std::endl;
}

void Harl::info()
{
	std::cout << "[ INFO ]" << std::endl
	<< "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
	<< std::endl << std::endl;
}

void Harl::warning()
{
	std::cout << "[ WARNING ]" << std::endl
	<< "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
	<< std::endl << std::endl;
}

void Harl::error()
{
	std::cout << "[ ERROR ]" << std::endl
	<< "This is unacceptable! I want to speak to the manager now."
	<< std::endl << std::endl;
}

void Harl::complain(void)
{
	switch (this->lvl)
	{
	case 0:
		this->debug();
		this->info();
		this->warning();
		this->error();
		break;
	case 1:
		this->info();
		this->warning();
		this->error();
		break ;
	case 2:
		this->warning();
		this->error();
		break ;
	case 3:
		this->error();
		break ;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break ;
	}
}
