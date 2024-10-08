/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 21:35:18 by mpitot            #+#    #+#             */
/*   Updated: 2024/10/07 10:53:09 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <Animal.hpp>

class Dog : public Animal
{
public:
/* Constructors */
	Dog();
	Dog(Dog const &src);

/* Destructors */
	~Dog();

/* Operators */
	Dog	&operator=(Dog const &src);

/* Actions */
	void makeSound() const;

};

#endif