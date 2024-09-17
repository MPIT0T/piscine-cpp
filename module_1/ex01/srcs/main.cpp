/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:05:12 by mpitot            #+#    #+#             */
/*   Updated: 2024/06/21 14:53:39 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name);

int	main()
{
	int		nb_z = 5;
	Zombie	*horde = zombieHorde(nb_z, "Terry");

	for (int i = 0; i < nb_z; i++)
		horde[i].announce();

	delete[] horde;
	return (0);
}