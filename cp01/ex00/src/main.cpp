/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:21:26 by whamdi            #+#    #+#             */
/*   Updated: 2024/10/17 16:37:34 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"
#include <ostream>
int main(void)
{
	Zombie *z;
	randomChump("Servietsky");	
	z = newZombie("Generic Zombie");
	std::cout << z->name << std::endl;
	delete z;
	return(0);
}
