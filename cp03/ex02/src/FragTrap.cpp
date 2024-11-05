/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:55:01 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/05 17:16:39 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap() 
{
	std::cout << "Constructor called for FragTrap" << std::endl;
	this->_name = name;
	this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDamage = 20;
}

FragTrap::FragTrap()
{	
	std::cout << "Constructor called for FragTrap" << std::endl;
	this->_name = "Default Robot";
	this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDamage = 20;
};
FragTrap::FragTrap(const FragTrap& other)
{
	*this = other;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap give you a high five buddy" << std::endl;
}
FragTrap & FragTrap::operator=(const FragTrap& other)
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
void FragTrap::attack(const std::string& target)
{
	if(this->_EnergyPoints == 0)
		return;
	std::cout << "FragTrap " << this->_name << " attacks "<< target << " causing " << this->_AttackDamage << std::endl;
	this->_EnergyPoints--;
}
FragTrap::~FragTrap()
{
	std::cout << "Destroy FragTrap" << std::endl;
}

void FragTrap::guardGate()
{
	std::cout << "FragTrap is now in Gate keeper mode." << std::endl;
}


