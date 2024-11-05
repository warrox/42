/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:25:24 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/05 17:23:39 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/ClapTrap.hpp"
#include <iostream>


ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Constructor called" << std::endl;
	this->_name = name;
	this->_HitPoints = 10;
	this->_EnergyPoints = 10;
	this->_AttackDamage = 0;
}
ClapTrap::ClapTrap()
{
	this->_name = "Default";
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
	if(this->_EnergyPoints == 0)
		return;
	std::cout << "ClapTrap " << this->_name << " attacks "<< target << " causing " << this->_AttackDamage << std::endl;
	this->_EnergyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " takes "<< amount << " damages "<< std::endl;
	if(this->_HitPoints <= 0)
		return;
	this->_HitPoints-= amount;
	
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(this->_EnergyPoints == 0)
		return;
	std::cout << "ClapTrap " << this->_name << " recover  "<< amount << " health points "  << std::endl;
	this->_HitPoints = 10;
	this->_EnergyPoints--;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	*this = other;
}
ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
	if(this != &other)
	{
		this->_name = other._name;
		this->_EnergyPoints = other._EnergyPoints;
		this->_HitPoints = other._HitPoints;
		this->_AttackDamage = other._AttackDamage;
	}
	return *this;
}


