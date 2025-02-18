/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:44:03 by mpitot            #+#    #+#             */
/*   Updated: 2024/10/13 23:04:45 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>

class AMateria
{
protected:
	std::string _type;

public:
/* Constructors */
	AMateria();
	explicit AMateria(std::string const &type);
	AMateria(AMateria const &src);

	virtual ~AMateria();

/* Operators */
	AMateria &operator=(AMateria const &src);

/* Getters */
	const std::string &getType() const;

/* Setters */
	void setType(const std::string &type);

/* Methods */
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target) = 0;
};

#endif