/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:06:03 by mpitot            #+#    #+#             */
/*   Updated: 2024/09/24 10:19:22 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

class ScavTrap : public ClapTrap
{
private:

public:
/* Constants **************************************************************** */
	static const std::string	SCAVTRAP_BASE_NAME;
	static const unsigned int	SCAVTRAP_BASE_HITPOINTS;
	static const unsigned int	SCAVTRAP_BASE_ENERGY_POINTS;
	static const unsigned int	SCAVTRAP_BASE_ATTACK_DAMAGE;

/* Constructors ************************************************************* */
	ScavTrap();
	ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap &other);

/* Operators **************************************************************** */
	ScavTrap &operator=(const ScavTrap &other);

/* Actions ****************************************************************** */
	void attack(const std::string &target);
	void guardGate();

/* Destructor *************************************************************** */
	~ScavTrap();
};

#endif
