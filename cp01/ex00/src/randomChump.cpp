/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:14:47 by whamdi            #+#    #+#             */
/*   Updated: 2024/10/11 10:53:05 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"
#include <ostream>

void randomChump( std::string name )
{
	Zombie* z = new Zombie;
	z->name = name;
	std::cout << z->name << " : ";
	z->announce();
	delete z;
}
