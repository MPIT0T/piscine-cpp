/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 21:35:18 by mpitot            #+#    #+#             */
/*   Updated: 2024/09/30 22:44:01 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <Animal.hpp>

class Dog : public Animal
{
private:

public:
/* Constructors */
	Dog();
	Dog(Dog const &src);

/* Operators */
	Dog	&operator=(Dog const &src);

/* Destructors */
	~Dog();
};

#endif