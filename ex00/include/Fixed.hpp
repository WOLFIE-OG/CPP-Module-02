/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:21:04 by otodd             #+#    #+#             */
/*   Updated: 2024/12/10 17:15:23 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H
# include <iostream>

class Fixed {
	private:
		int					_fixedVal;
		const static int	_FRACTIONAL_BITS;
	
	public:
		Fixed(void);
		Fixed(const Fixed &cpy);
		~Fixed(void);
		Fixed &operator=(const Fixed &src);

	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif