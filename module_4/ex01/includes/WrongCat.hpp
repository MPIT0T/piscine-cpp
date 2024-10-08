/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:29:03 by mpitot            #+#    #+#             */
/*   Updated: 2024/10/07 13:48:51 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <WrongAnimal.hpp>

class WrongCat : public WrongAnimal
{
public:
/* Constructors */
	WrongCat();
	WrongCat(WrongCat const &src);

/* Destructors */
	~WrongCat();

/* Operators */
	WrongCat	&operator=(WrongCat const &src);

/* Actions */
	void makeSound() const;
};

#endif