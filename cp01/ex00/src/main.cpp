/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:21:26 by whamdi            #+#    #+#             */
/*   Updated: 2024/10/10 16:20:10 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"
#include <ostream>
int main(void)
{
	Zombie *z;
	randomChump("Servietsky");	
	z = newZombie("YO");
	std::cout << z->name << std::endl;
	delete z;
	return(0);
}
