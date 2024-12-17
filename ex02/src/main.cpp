/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:20:50 by otodd             #+#    #+#             */
/*   Updated: 2024/12/17 13:24:16 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

void	main_tests()
{
	Fixed			a;
	Fixed	const	b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;
	
	std::cout << Fixed::max(a, b) << std::endl << std::endl;
}

void	multi(std::string letter, Fixed &var)
{
	std::cout << letter << ": " << var << std::endl;
	std::cout << letter << "--: " << var-- << std::endl;
	std::cout << letter << ": " << var << std::endl;
	std::cout << '(' << letter << " * 12): " << (var * 12) << std::endl;
	std::cout << letter << ": " << var << std::endl;
	std::cout << '(' << letter << " / 12): " << (var / 12) << std::endl;
	std::cout << letter << ": " << var << std::endl;
	std::cout << "--" << letter << ": " << --var << std::endl;
	std::cout << letter << ": " << var << std::endl;
	std::cout << '(' << letter << " - 12): " << (var - 12) << std::endl;
	std::cout << letter << ": " << var << std::endl;
	std::cout << letter << "++: " << var++ << std::endl;
	std::cout << letter << ": " << var << std::endl << std::endl;
}

void	own_tests()
{
	Fixed	a;
	Fixed	b(Fixed(5.05f) * Fixed(2));
	Fixed	c(Fixed(9.45f) / Fixed(8));
	Fixed	d(Fixed(2.06f) + Fixed(4));
	Fixed	e(Fixed(3.05f) * Fixed(7));
	Fixed	f(Fixed(50.23f) / Fixed(15));
	Fixed	g(Fixed(144.23f) + Fixed(5));
	Fixed	h(Fixed(1.23f) - Fixed(14));

	multi("a", a);
	multi("b", b);
	multi("c", c);
	multi("d", d);
	multi("e", e);
	multi("f", f);
	multi("g", g);
	multi("h", h);

	std::cout << "(a == b): " << (a == b) << std::endl;
	std::cout << "(c != d): " << (c != d) << std::endl;
	std::cout << "(e < f): " << (e < f) << std::endl;
	std::cout << "(g > h): " << (g > h) << std::endl;
	std::cout << "(a >= f): " << (a >= f) << std::endl;
	std::cout << "(h <= e): " << (h <= e) << std::endl << std::endl;

	std::cout << "Fixed::min(a, b): " << Fixed::min(a, b) << std::endl;
	std::cout << "Fixed::max(a, b): " << Fixed::max(a, b) << std::endl << std::endl;
	std::cout << "Fixed::min(c, d): " << Fixed::min(c, d) << std::endl;
	std::cout << "Fixed::max(c, d): " << Fixed::max(c, d) << std::endl << std::endl;
	std::cout << "Fixed::min(e, f): " << Fixed::min(e, f) << std::endl;
	std::cout << "Fixed::max(e, f): " << Fixed::max(e, f) << std::endl << std::endl;
	std::cout << "Fixed::min(g, h): " << Fixed::min(g, h) << std::endl;
	std::cout << "Fixed::max(g, h): " << Fixed::max(g, h) << std::endl;
}

int	main(void)
{
	main_tests();
	own_tests();
	return 0;
}