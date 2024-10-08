/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:02:48 by mpitot            #+#    #+#             */
/*   Updated: 2024/06/21 15:09:23 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class	Zombie
{
private:
	std::string	_name;

public:
	void	setName(std::string name);

	Zombie();
	Zombie(std::string name);
	~Zombie(void);

	void	announce(void);
};

#endif