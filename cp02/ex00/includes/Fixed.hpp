/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:38:03 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/01 09:53:43 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
#define FIXED_HPP


class Fixed
{
private :
		int _value;
		static const int _fractional_b;
	public:
		int getRawBits(void)const;
		void setRawbits(int const raw);
        Fixed ();
        Fixed (const Fixed&);
		Fixed &operator=(const Fixed&);
        ~Fixed ();
};
#endif
