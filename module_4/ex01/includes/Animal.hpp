/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 21:25:37 by mpitot            #+#    #+#             */
/*   Updated: 2024/10/07 11:03:10 by mpitot           ###   ########.fr       */
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
	Animal(Animal const &src);

/* Operators */
	Animal	&operator=(Animal const &src);

/* Destructors */
	virtual ~Animal();

/* Actions */
	virtual void	makeSound() const;

/* Getters */
	std::string		getType() const;

/* Setters */
    void			setType(std::string type);
};

#endif
