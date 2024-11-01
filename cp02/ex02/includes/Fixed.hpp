/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:38:03 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/01 10:08:34 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>
class Fixed
{
private :
		int _value;
		static const int _fractional_b;
	public:
		int getRawBits(void)const;
		void setRawbits(int const raw);
        Fixed ();
		Fixed(const int fixedPoint);
		Fixed(const float fixedPoint);
        Fixed (const Fixed&);
		Fixed &operator=(const Fixed&);
		bool  operator>=(const Fixed &other);
		bool operator<=(const Fixed&other);
		bool operator<(const Fixed&other);
		bool operator>(const Fixed&other);
		bool operator!=(const Fixed&other);
		bool operator==(const Fixed&other);
		float operator+(const Fixed&other);
		float operator-(const Fixed&other);
		float operator*(const Fixed&other);
		float operator/(const Fixed&other);	
		Fixed operator++();
		Fixed operator--();
		Fixed operator++(int);
		Fixed operator--(int);
		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
		float  toFloat(void) const;
		int    toInt(void) const;
        ~Fixed ();
};
std::ostream &operator<<(std::ostream &o, const Fixed &fixed);
#endif
