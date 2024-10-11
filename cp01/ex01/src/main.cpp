/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:26:46 by whamdi            #+#    #+#             */
/*   Updated: 2024/10/11 10:31:31 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"


int main(int argc, char **argv)
{
	(void) argc, (void) argv;
	std::string name = "test"; 
	int proto = 2;

	zombieHorde(proto, name);
	return(0);
}
