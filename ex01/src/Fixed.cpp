/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:21:21 by otodd             #+#    #+#             */
/*   Updated: 2024/12/10 18:39:05 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

const int	Fixed::_FRACTIONAL_BITS = 8;

Fixed::Fixed(void) : _fixedVal(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int in)
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(in << Fixed::_FRACTIONAL_BITS);
}

Fixed::Fixed(const float in)
{
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits(round(in * (1 << Fixed::_FRACTIONAL_BITS)));
}

Fixed::Fixed(const Fixed &cpy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = cpy;
}

Fixed	&Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->setRawBits(src.getRawBits());
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	return this->_fixedVal;
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedVal = raw;
}

float	Fixed::toFloat(void) const
{
	return this->getRawBits() / (float)(1 << Fixed::_FRACTIONAL_BITS);
}

int		Fixed::toInt(void) const
{
	return this->getRawBits() >> Fixed::_FRACTIONAL_BITS;
}

std::ostream	&operator<<(std::ostream &out, const Fixed &f)
{
	float t = f.toFloat();
	out << t;
	return out;
}