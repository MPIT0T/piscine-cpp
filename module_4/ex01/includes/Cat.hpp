/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 21:31:46 by mpitot            #+#    #+#             */
/*   Updated: 2024/10/07 11:01:33 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain	*_brain;

public:
/* Constructors */
	Cat();
	Cat(Cat const &src);

/* Operators */
	Cat	&operator=(Cat const &src);

/* Destructors */
	~Cat();

/* Actions */
	void makeSound() const;

};

#endif
