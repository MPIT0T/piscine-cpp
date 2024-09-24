/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:19:46 by mpitot            #+#    #+#             */
/*   Updated: 2024/09/19 15:09:33 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int Fixed::_fractional_bits = 8;

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _value(value << _fractional_bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _value(roundf(value * (1 << _fractional_bits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	if (this != &src)
		*this = src;
}

//////////////////////////////////////////////////////

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

//////////////////////////////////////////////////////

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &src)
		return (*this);
	_value = src.getRawBits();
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, const Fixed &src)
{
	os << src.toFloat();
	return (os);
}

//////////////////////////////////////////////////////

int Fixed::getRawBits(void) const
{
	return (_value);
}

void Fixed::setRawBits(const int raw)
{
	_value = raw;
}

//////////////////////////////////////////////////////

float Fixed::toFloat(void) const
{
	return ((float) this->getRawBits() / (1 << _fractional_bits));
}

int	Fixed::toInt(void) const
{
	return (this->getRawBits() >> _fractional_bits);
}
