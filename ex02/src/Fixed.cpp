/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:21:21 by otodd             #+#    #+#             */
/*   Updated: 2024/12/17 13:23:46 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

const int	Fixed::_FRACTIONAL_BITS = 8;

Fixed::Fixed(void) : _fixedVal(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int in)
{
	// std::cout << "Int constructor called" << std::endl;
	this->setRawBits(in << Fixed::_FRACTIONAL_BITS);
}

Fixed::Fixed(const float in)
{
	// std::cout << "Float constructor called" << std::endl;
	this->setRawBits(round(in * (1 << Fixed::_FRACTIONAL_BITS)));
}

Fixed::Fixed(const Fixed &cpy)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = cpy;
}

Fixed	&Fixed::operator=(const Fixed &src)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->setRawBits(src.getRawBits());
	return *this;
}

bool	Fixed::operator<(const Fixed &f) const
{
	return this->toFloat() < f.toFloat();
}

bool	Fixed::operator>(const Fixed &f) const
{
	return this->toFloat() > f.toFloat();
}

bool	Fixed::operator>=(const Fixed &f) const
{
	return this->toFloat() >= f.toFloat();
}

bool	Fixed::operator<=(const Fixed &f) const
{
	return this->toFloat() <= f.toFloat();
}

bool	Fixed::operator==(const Fixed &f) const
{
	return this->toFloat() == f.toFloat();
}

bool	Fixed::operator!=(const Fixed &f) const
{
	return this->toFloat() != f.toFloat();
}

Fixed 	Fixed::operator++(int)
{
	// std::cout << "Post increment operator called" << std::endl;
	Fixed post = *this;
	this->setRawBits(++this->_fixedVal);
	return post;
}
Fixed 	Fixed::operator--(int)
{
	// std::cout << "Post deincrement operator called" << std::endl;
	Fixed post = *this;
	this->setRawBits(--this->_fixedVal);
	return post;
}

Fixed 	&Fixed::operator++(void)
{
	// std::cout << "Pre increment operator called" << std::endl;
	this->setRawBits(++this->_fixedVal);
	return *this;
}

Fixed 	&Fixed::operator--(void)
{
	// std::cout << "Pre deincrement operator called" << std::endl;
	this->setRawBits(--this->_fixedVal);
	return *this;
}

Fixed 	Fixed::operator+(const Fixed &f) const
{
	return Fixed(this->toFloat() + f.toFloat());
}

Fixed 	Fixed::operator-(const Fixed &f) const
{
	return Fixed(this->toFloat() - f.toFloat());
}

Fixed 	Fixed::operator*(const Fixed &f) const
{
	return Fixed(this->toFloat() * f.toFloat());
}

Fixed 	Fixed::operator/(const Fixed &f) const
{
	return Fixed(this->toFloat() / f.toFloat());
}

Fixed 	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a.toFloat() < b.toFloat())
		return a;
	return b;
}

const Fixed 	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() < b.toFloat())
		return a;
	return b;
}

Fixed 	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a.toFloat() > b.toFloat())
		return a;
	return b;
}

const Fixed 	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() > b.toFloat())
		return a;
	return b;
}

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called" << std::endl;
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
