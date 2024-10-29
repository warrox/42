/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:26:46 by whamdi            #+#    #+#             */
/*   Updated: 2024/10/29 14:05:07 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"
#include <cstdio>
#include <sstream>
#include <string>
#include <iostream>

int main(int argc, char **argv)
{
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <number_of_zombies> <zombie_name>" << std::endl;
        return 1;
    }

    std::stringstream ss(argv[1]);
    int n;
    ss >> n;

    if (ss.fail() || !ss.eof()) {
        std::cerr << "Invalid number: " << argv[1] << std::endl;
        return 1;
    }

    std::string name = argv[2];

    Zombie *z = zombieHorde(n, name);
	for(int i = 0; i < n; i++)
	{
		z[i].announce();
	}    
    delete [] z;
    return 0;
}
