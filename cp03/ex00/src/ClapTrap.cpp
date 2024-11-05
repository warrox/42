/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:25:24 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/05 15:13:35 by whamdi           ###   ########.fr       */
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
	//TODO: handle underflows
	this->_HitPoints-= amount;
	
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(this->_EnergyPoints == 0)
		return;
	std::cout << "ClapTrap " << this->_name << " recover  "<< amount << " health points "  << std::endl;
	//TODO: increment hitpoint of amount
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


