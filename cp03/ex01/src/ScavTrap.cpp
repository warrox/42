/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:06:54 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/05 16:37:25 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name): ClapTrap() 
{
	std::cout << "Constructor called for ScavTrap" << std::endl;
	this->_name = name;
}

ScavTrap::ScavTrap()
{	
	std::cout << "Constructor called for ScavTrap" << std::endl;
	this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDamage = 20;
};
void ScavTrap::attack(const std::string& target)
{
	if(this->_EnergyPoints == 0)
		return;
	std::cout << "ScavTrap " << this->_name << " attacks "<< target << " causing " << this->_AttackDamage << std::endl;
	this->_EnergyPoints--;
}
ScavTrap::~ScavTrap()
{
	std::cout << "Destroy ScavTrap" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}

