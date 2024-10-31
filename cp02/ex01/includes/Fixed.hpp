/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:38:03 by whamdi            #+#    #+#             */
/*   Updated: 2024/10/31 11:45:06 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
class Fixed
{
private :
		int _value;
		static const int _fractional_b;
	public:
		int getRawBits(void)const;
        Fixed ();
		Fixed(const int fixedPoint);
		Fixed(const float fixedPoint);
        Fixed (const Fixed&);
		Fixed &operator=(const Fixed&);
		float  toFloat(void) const;
		int    toInt(void) const;
        ~Fixed ();
};
#endif
