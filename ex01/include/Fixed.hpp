/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:21:04 by otodd             #+#    #+#             */
/*   Updated: 2024/12/10 18:25:42 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H
# include <iostream>
# include <cmath>

class Fixed {
	private:
		int					_fixedVal;
		const static int	_FRACTIONAL_BITS;
	
	public:
		Fixed(void);
		Fixed(const int in);
		Fixed(const float in);
		Fixed(const Fixed &cpy);
		~Fixed(void);
		Fixed &operator=(const Fixed &src);
		float	toFloat(void) const;
		int		toInt(void) const;

	int getRawBits(void) const;
	void setRawBits(int const raw);
};

std::ostream	&operator<<(std::ostream &out, const Fixed &f);

#endif