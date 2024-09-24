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
	ClapTrap parent;
	ScavTrap child("Hola");
	ScavTrap child2(child);

	// child.attack("Walter");
	// parent.takeDamage(child.SCAVTRAP_BASE_ATTACK_DAMAGE);
	// parent.beRepaired(10);
	// parent.attack("child2");
	// child2.beRepaired(3);
	return (0);
}