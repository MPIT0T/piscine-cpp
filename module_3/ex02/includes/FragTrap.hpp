/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:41:31 by mpitot            #+#    #+#             */
/*   Updated: 2024/09/24 15:07:01 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

class FragTrap : public ClapTrap
{
private:

public:
/* Constants **************************************************************** */
	static const std::string	FRAGTRAP_BASE_NAME;
	static const unsigned int	FRAGTRAP_BASE_HITPOINTS;
	static const unsigned int	FRAGTRAP_BASE_ENERGY_POINTS;
	static const unsigned int	FRAGTRAP_BASE_ATTACK_DAMAGE;

/* Constructors ************************************************************* */
	FragTrap();
	FragTrap(const std::string& name);
	FragTrap(const FragTrap &other);

/* Operators **************************************************************** */
	FragTrap &operator=(const FragTrap &other);

/* Actions ****************************************************************** */
	void	highFivesGuys() const;

/* Destructor *************************************************************** */
	~FragTrap();
};

#endif