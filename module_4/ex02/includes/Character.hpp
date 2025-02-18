/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:31:20 by mpitot            #+#    #+#             */
/*   Updated: 2024/10/14 09:48:06 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include "AMateria.hpp"

class Character
{
private:
	std::string _name;
	AMateria	*_inventory[4];

public:
/* Constructors */
	Character();
	Character(std::string const &name);
	Character(Character const &src);

	~Character();

/* Operators */
	Character	&operator=(Character const &src);

/* Getters */
	const std::string &getName() const;

/* Setters */
	void		setName(const std::string &name);
	void		equip(AMateria *m);
	void		unequip(int i);

/* Methods */
	void	use(int i, ICharacter &target);
};

#endif
