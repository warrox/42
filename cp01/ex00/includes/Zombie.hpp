/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:04:10 by whamdi            #+#    #+#             */
/*   Updated: 2024/10/11 10:50:38 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP


#include <iostream>
#include <string>

class Zombie
{
public : 
	std::string name;
	void announce(void);
};

void randomChump( std::string name );
Zombie* newZombie( std::string name ); 
// Zombie* zombieHorde( int N, std::string name );
#endif
