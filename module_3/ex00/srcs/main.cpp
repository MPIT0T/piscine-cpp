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

	steve.attack("Eve");
	steve.takeDamage(2);
	steve.beRepaired(1);

	eve.attack("Steve");
	eve.takeDamage(2);
	eve.beRepaired(1);

	return (0);
}