/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:38:03 by whamdi            #+#    #+#             */
/*   Updated: 2024/10/16 15:39:25 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
#define FIXED_HPP


class T
{
    public:
        T (); // Constructeur par défaut
        T (const T&); // Constructeur de recopie
        ~T (); // Destructeur éventuellement virtuel
        T &operator=(const T&); // Operator d'affectation
};
#endif // !DEBUG
