/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:25:24 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/01 12:03:55 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/ClapTrap.hpp"
#include <iostream>
// class ClapTrap
// {
// 	private :
// 		std::string _name;
// 		int _HitPoints;
// 		int _EnergyPoints;
// 		int _AttackDamage;
// 	public :
// 		void attack(const std::string& target);
// 		void takeDamage(unsigned int amount);
// 		void beRepaired(unsigned int amount);
// 		ClapTrap(std::string name);
// }
//

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Constructor called" << std::endl;
	this->_name = name;
	this->_HitPoints = 10;
	this->_EnergyPoints = 10;
	this->_AttackDamage = 0;
}
ClapTrap::~ClapTrap()
{
	std::cout << "Destroy ClapTrap" << std::endl;
}
void ClapTrap::attack(const std::string& target)
{
//ClapTrap <name> attacks <target>, causing <damage> points of damage!	
	if(this->_EnergyPoints == 0)
		return;
	std::cout << "ClapTrap " << this->_name << " attacks "<< target << " causing " << this->_AttackDamage << std::endl;
	this->_EnergyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " takes "<< amount << " damages "<< std::endl;
	this->_HitPoints-= amount;
	
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(this->_EnergyPoints == 0)
		return;
	std::cout << "ClapTrap " << this->_name << " recover  "<< amount << " health points "  << std::endl;
	this->_EnergyPoints--;
}
