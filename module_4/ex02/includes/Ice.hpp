/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:23:21 by mpitot            #+#    #+#             */
/*   Updated: 2024/10/14 09:23:21 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include <string>

class Ice : public AMateria
{
public:
/* Constructors */
	Ice();
	Ice(std::string const &type);
	Ice(Ice const &src);

	~Ice();

/* Operators */
	Ice			&operator=(Ice const &src);

/* Methods */
	AMateria	*clone() const;
	void		use(ICharacter &target);
};


#endif