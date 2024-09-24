/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:19:06 by mpitot            #+#    #+#             */
/*   Updated: 2024/09/18 11:02:05 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
private:
	int					_value;
	static const int	fractional_bits;

public:
	Fixed(void);
	~Fixed(void);

	Fixed(const Fixed &src);
	Fixed &operator=(const Fixed &src);

	int		getRawBits(void) const;
	void	setRawBits(const int raw);
} ;

#endif