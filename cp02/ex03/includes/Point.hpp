/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:26:20 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/01 10:26:49 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Fixed.hpp"


class Point
{
	private:
		const Fixed _x;
		const Fixed _y;

	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& copy);

		~Point();

		Point &operator=(const Point &src);


		const Fixed &getX(void)const;
		const Fixed &getY(void)const;

};

std::ostream	&operator<<(std::ostream &o, Point const point);
