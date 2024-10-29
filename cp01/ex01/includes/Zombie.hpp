/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:04:10 by whamdi            #+#    #+#             */
/*   Updated: 2024/10/29 11:55:49 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP


#include <iostream>
#include <string>

class Zombie
{
public : 
	Zombie();
	std::string name;
	void announce(void);
	~Zombie();
};

void randomChump( std::string name );

Zombie* newZombie( std::string name ); 
Zombie* zombieHorde( int N, std::string name );
// Zombie* zombieHorde( int N, std::string name );
#endif
