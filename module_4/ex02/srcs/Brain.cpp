/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:25:20 by mpitot            #+#    #+#             */
/*   Updated: 2024/10/08 12:35:09 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

/* Constructors ************************************************************* */
Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = "";
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = copy._ideas[i];
}

/* Destructor *************************************************************** */
Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

/* Operator overloads ******************************************************* */
Brain &Brain::operator=(const Brain &src)
{
	std::cout << "Brain assignation operator called" << std::endl;
	if (this != &src)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = src._ideas[i];
	}
	return *this;
}

/* Member functions ******************************************************** */
void	Brain::addIdea(const std::string &idea)
{
	for (int i = 0; i < 100; i++)
	{
		if (this->_ideas[i].empty())
		{
			this->_ideas[i] = idea;
			return ;
		}
	}
}

void	Brain::setIdea(const int index, const std::string &idea)
{
	if (index >= 0 && index < 100)
		this->_ideas[index] = idea;
}

void	Brain::displayIdeas() const
{
	for (int i = 0; i < 100; i++)
	{
		if (!this->_ideas[i].empty())
			std::cout << "Idea " << i << ": " << _ideas[i] << std::endl;
	}
}
