/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:42:06 by mpitot            #+#    #+#             */
/*   Updated: 2024/09/23 13:23:36 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

class ClapTrap
{
protected:
	std::string		_name;
	unsigned int	_hitpoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;

public:
/* Constants **************************************************************** */

	static const std::string	CLAPTRAP_BASE_NAME;
	static const unsigned int	CLAPTRAP_BASE_HITPOINTS;
	static const unsigned int	CLAPTRAP_BASE_ENERGY_POINTS;
	static const unsigned int	CLAPTRAP_BASE_ATTACK_DAMAGE;

/* Constructors ************************************************************* */
	ClapTrap();
	ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap &other);

/* Operators **************************************************************** */
	ClapTrap	&operator=(const ClapTrap &other);

/* Actions ****************************************************************** */
	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

/* Destructor *************************************************************** */
	~ClapTrap();
};

#endif