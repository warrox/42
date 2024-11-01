/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:17:53 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/01 11:06:50 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/Point.hpp"

bool bsp(const Point a, const Point b, const Point c, const Point point);

int main(void)
{
	{
	const Point a;
	const Point b(10, 0);
	const Point c(0, 10);
	const Point point(1, 1);

	if (bsp(a, b, c, point) == true)
		std::cout << "TRUE" << std::endl;
	else
		std::cout << "FALSE" << std::endl;
	}
	std::cout << "\n---------------------------------------------------------------------\n" << std::endl;
	{
	Point a(-1.5, -1.5);
	Point b(2.5, 2.5);
	Point c(-1, -2);
	Point point(8.5, -9);

	if (bsp(a, b, c, point) == true)
		std::cout << "TRUE" << std::endl;
	else
		std::cout << "FALSE" << std::endl;
	}
	return (0);
}
