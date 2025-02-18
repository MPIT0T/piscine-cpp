/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:59:17 by mpitot            #+#    #+#             */
/*   Updated: 2024/10/14 09:16:26 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <AMateria.hpp>

class Cure : public AMateria
{
public:
/* Constructors */
	Cure();
	Cure(std::string const &type);
	Cure(Cure const &src);

	~Cure();

/* Operators */
	Cure		&operator=(Cure const &src);

/* Methods */
	AMateria	*clone() const;
	void		use(ICharacter &target);
};

#endif