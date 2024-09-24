/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:41:34 by mpitot            #+#    #+#             */
/*   Updated: 2024/09/24 15:45:06 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/* Constants **************************************************************** */
const std::string	FragTrap::FRAGTRAP_BASE_NAME = "default";
const unsigned int	FragTrap::FRAGTRAP_BASE_HITPOINTS = 100;
const unsigned int	FragTrap::FRAGTRAP_BASE_ENERGY_POINTS = 100;
const unsigned int	FragTrap::FRAGTRAP_BASE_ATTACK_DAMAGE = 30;

/* Constructors ************************************************************* */
FragTrap::FragTrap()
{
	this->_hitpoints = FRAGTRAP_BASE_HITPOINTS;
	this->_energyPoints = FRAGTRAP_BASE_ENERGY_POINTS;
	this->_attackDamage = FRAGTRAP_BASE_ATTACK_DAMAGE;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	this->_hitpoints = FRAGTRAP_BASE_HITPOINTS;
	this->_energyPoints = FRAGTRAP_BASE_ENERGY_POINTS;
	this->_attackDamage = FRAGTRAP_BASE_ATTACK_DAMAGE;
	std::cout << "FragTrap " << this->_name << " constructor called" <<
		std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	*this = other;
	std::cout << "FragTrap copy constructor called" << std::endl;
}

/* Operators **************************************************************** */
FragTrap &FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitpoints = other._hitpoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

/* Actions ****************************************************************** */
void FragTrap::highFivesGuys() const
{
	std::cout << "FragTrap " << this->_name << " high fives guys" << std::endl;
}

/* Destructor *************************************************************** */
FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}
