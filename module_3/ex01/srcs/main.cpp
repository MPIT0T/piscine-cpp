/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:44:04 by mpitot            #+#    #+#             */
/*   Updated: 2024/09/24 14:21:12 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ScavTrap.hpp>

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	parent("Joel");
	ScavTrap	child("Ellie");

	std::cout << std::endl;


	parent.attack("Ellie");
	child.attack("Joel");

	std::cout << std::endl;

	parent.takeDamage(1);
	child.takeDamage(1);

	std::cout << std::endl;

	parent.beRepaired(10);
	child.beRepaired(10);

	std::cout << std::endl;

	child.guardGate();
	// parent.guardGate();

	std::cout << std::endl;

	parent.takeDamage(9);
	child.takeDamage(100);

	std::cout << std::endl;

	return (0);
}