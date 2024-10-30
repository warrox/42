/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:38:03 by whamdi            #+#    #+#             */
/*   Updated: 2024/10/30 17:19:34 by whamdi           ###   ########.fr       */
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
        Fixed (); // Constructeur par défaut
        Fixed (const Fixed&); // Constructeur de recopie
		Fixed &operator=(const Fixed&); // Operator d'affectation
        ~Fixed (); // Destructeur éventuellement virtuel
};
#endif
