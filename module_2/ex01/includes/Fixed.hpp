/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:19:06 by mpitot            #+#    #+#             */
/*   Updated: 2024/09/19 15:05:32 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
private:
	int					_value;
	static const int	_fractional_bits;

public:
	Fixed(void);
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &src);

	//////////////////////////////////////////////////////

	~Fixed(void);

	//////////////////////////////////////////////////////

	Fixed			&operator=(const Fixed &src);

	//////////////////////////////////////////////////////

	int		getRawBits(void) const;
	void	setRawBits(const int raw);

	//////////////////////////////////////////////////////

	float	toFloat(void) const;
	int		toInt(void) const;
} ;

std::ostream	&operator<<(std::ostream &OUT, const Fixed &src);

#endif