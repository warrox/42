/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:21:26 by whamdi            #+#    #+#             */
/*   Updated: 2024/10/29 11:48:21 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"
#include <ostream>
int main(void)
{
	Zombie z("Dark vador");
	Zombie *test;
	z.announce();
	test = z.newZombie("Guts");
	test->announce();
	delete(test);
	randomChump("Servietsky");
	return(0);
}
