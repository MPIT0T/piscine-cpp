/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:19:06 by mpitot            #+#    #+#             */
/*   Updated: 2024/09/23 11:32:18 by mpitot           ###   ########.fr       */
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

	Fixed	&operator=(const Fixed &src);

	bool	operator>(const Fixed &src) const;
	bool	operator<(const Fixed &src) const;
	bool	operator>=(const Fixed &src) const;
	bool	operator<=(const Fixed &src) const;
	bool	operator==(const Fixed &src) const;
	bool	operator!=(const Fixed &src) const;

	Fixed	operator+(const Fixed &src) const;
	Fixed	operator-(const Fixed &src) const;
	Fixed	operator*(const Fixed &src) const;
	Fixed	operator/(const Fixed &src) const;

	Fixed	operator++(int);
	Fixed	operator--(int);
	Fixed	&operator++(void);
	Fixed	&operator--(void);

	//////////////////////////////////////////////////////

	int		getRawBits(void) const;
	void	setRawBits(const int raw);

	//////////////////////////////////////////////////////

	float	toFloat(void) const;
	int		toInt(void) const;

	//////////////////////////////////////////////////////

	static const Fixed	max(const Fixed &a, const Fixed &b);
	static const Fixed	min(const Fixed &a, const Fixed &b);
	static Fixed	max(Fixed &a, Fixed &b);
	static Fixed	min(Fixed &a, Fixed &b);
} ;

std::ostream	&operator<<(std::ostream &OUT, const Fixed &src);

#endif