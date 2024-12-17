/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:21:04 by otodd             #+#    #+#             */
/*   Updated: 2024/12/16 19:27:09 by otodd            ###   ########.fr       */
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

		Fixed				&operator=(const Fixed &src);
		
		bool				operator<(const Fixed &f) const;
		bool				operator>(const Fixed &f) const;
		bool				operator>=(const Fixed &f) const;
		bool				operator<=(const Fixed &f) const;
		bool				operator==(const Fixed &f) const;
		bool				operator!=(const Fixed &f) const;
		
		Fixed 				operator++(int);
		Fixed 				operator--(int);
		Fixed 				&operator++(void);
		Fixed 				&operator--(void);
		
		Fixed 				operator+(const Fixed &f) const;
		Fixed 				operator-(const Fixed &f) const;
		Fixed 				operator*(const Fixed &f) const;
		Fixed 				operator/(const Fixed &f) const;
		
		float				toFloat(void) const;
		int					toInt(void) const;
		static Fixed 		&min(Fixed &a, Fixed &b);
		static const Fixed 	&min(const Fixed &a, const Fixed &b);
		static Fixed 		&max(Fixed &a, Fixed &b);
		static const Fixed 	&max(const Fixed &a, const Fixed &b);

	int 					getRawBits(void) const;
	void 					setRawBits(int const raw);
};

std::ostream				&operator<<(std::ostream &out, const Fixed &f);

#endif