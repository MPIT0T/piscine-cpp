/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:44:04 by mpitot            #+#    #+#             */
/*   Updated: 2024/09/23 14:42:10 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap steve("Steve");
	ClapTrap eve("Eve");

	std::cout << std::endl;

	steve.attack("Eve");
	eve.takeDamage(1);
	eve.beRepaired(1);

	std::cout << std::endl;

	eve.attack("Steve");
	steve.takeDamage(1);
	steve.beRepaired(2);

	std::cout << std::endl;

	steve.takeDamage(10);
	eve.takeDamage(10);

	std::cout << std::endl;

	return (0);
}