/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:04:57 by mpitot            #+#    #+#             */
/*   Updated: 2024/10/07 11:07:03 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class	WrongAnimal
{
protected:
	std::string	_type;

public:
	/* Constructors */
	WrongAnimal();
	WrongAnimal(WrongAnimal const &src);

	/* Operators */
	WrongAnimal	&operator=(WrongAnimal const &src);

	/* Destructors */
	virtual ~WrongAnimal();

	/* Actions */
	virtual void	makeSound() const;

	/* Getters */
	std::string		getType() const;

	/* Setters */
	void			setType(std::string type);
};

#endif