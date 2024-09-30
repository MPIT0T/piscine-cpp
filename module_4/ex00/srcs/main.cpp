/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:44:04 by mpitot            #+#    #+#             */
/*   Updated: 2024/09/24 15:43:59 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap parent("Linda");
	ScavTrap sChild("Phineas");
	FragTrap fChild("Ferb");

	std::cout << std::endl;

	parent.attack("Candice");
	sChild.attack("Candice");
	fChild.attack("Candice");

	std::cout << std::endl;

	parent.takeDamage(10);
	sChild.takeDamage(10);
	fChild.takeDamage(10);

	std::cout << std::endl;

	parent.beRepaired(5);
	sChild.beRepaired(5);
	fChild.beRepaired(5);

	std::cout << std::endl;

	// parent.guardGate();
	sChild.guardGate();
	// fChild.guardGate();

	std::cout << std::endl;

	// parent.highFivesGuys();
	// sChild.highFivesGuys();
	fChild.highFivesGuys();

	std::cout << std::endl;


	return (0);
}