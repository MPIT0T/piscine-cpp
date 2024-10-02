/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 21:25:37 by mpitot            #+#    #+#             */
/*   Updated: 2024/10/01 17:08:18 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class	Animal
{
protected:
	std::string	_type;

public:
/* Constructors */
	Animal();
	explicit Animal(std::string type);
	Animal(Animal const &src);

/* Operators */
	Animal	&operator=(Animal const &src);

/* Destructors */
	~Animal();

/* Actions */
	virtual void	makeSound() const;

/* Getters */
	std::string		getType() const;
};

#endif
