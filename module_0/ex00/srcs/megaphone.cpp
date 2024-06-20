/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 18:19:48 by mpitot            #+#    #+#             */
/*   Updated: 2024/06/20 17:24:43 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <bits/fs_ops.h>

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}

	std::string		input;

	for (int i = 1; i < ac; i++)
	{
		input += av[i];
		if (av[i + 1])
			input += " ";
	}

	for (size_t i = 0; i < input.length(); i++)
		std::cout << (char) std::toupper(input[i]);
	std::cout << std::endl;
	return (0);
}
