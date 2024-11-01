/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:06:54 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/01 15:23:16 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScapTrap::ScapTrap(): ClapTrap("Scap's parent") 
{
	std::cout << "Constructor called" << std::endl;
}

ScapTrap::~ScapTrap()
{
	std::cout << "Destroy Scap Trap" << std::endl;
}

void ScapTrap::guardGate()
{
	std::cout << " ScavTrap is now in Gate keeper mode." << std::endl;
}

