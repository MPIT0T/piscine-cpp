/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:07:56 by mpitot            #+#    #+#             */
/*   Updated: 2024/06/21 15:20:28 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

void Zombie::announce()
{
	std::cout << this->name << ": "
			  << " BraiiiiiiinnnzzzZ..."
			  << std::endl;
}

Zombie::Zombie() {}
Zombie::Zombie(std::string name) {this->name = name;}

Zombie::~Zombie()
{
	std::cout << this->name
			  << ": dead"
			  << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}
