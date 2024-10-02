/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 21:31:46 by mpitot            #+#    #+#             */
/*   Updated: 2024/09/30 21:39:52 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <Animal.hpp>

class Cat : public Animal
{
private:

public:
/* Constructors */
	Cat();
	Cat(Cat const &src);

/* Operators */
	Cat	&operator=(Cat const &src);

/* Destructors */
	~Cat();
};

#endif
