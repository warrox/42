/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:24:16 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/14 14:09:17 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"
#include <iostream>


// Character::Character(){};
Character::Character(std::string type) : _type(type)
{
	std::cout << "Character constructor called" << std::endl;	
	//Bzero 
	for (int i = 0; i < INVENTORY_SIZE; i++)
		this->_inventory[i] = 0;
}

Character::~Character()
{
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		delete this->_inventory[i];
	}
	std::cout << "\033[31mCharacter destructor called\033[0m" << std::endl;
}

Character::Character(const Character &other)
{
	for (int i = 0; i < INVENTORY_SIZE;i++)
	{
		delete this->_inventory[i];
	}
	this->_type = other._type;
	for(int i = 0; i < INVENTORY_SIZE;i++)
	{
		if(other._inventory[i] != 0)
			this->_inventory[i] = other._inventory[i]->clone();
	}
}

Character & Character::operator=(const Character &other)
{
	for (int i = 0; i < INVENTORY_SIZE;i++)
	{
		delete this->_inventory[i];
	}
	if(this != &other)
	{
		this->_type = other._type;
		for(int i = 0; i < INVENTORY_SIZE;i++)
		{
			if(other._inventory[i] != 0)
				this->_inventory[i] = other._inventory[i]->clone();
		}
	}
	return(*this);
}
std::string const & Character::getName()const 
{
	return(this->_type);
}

//equip
void Character::equip(AMateria* m)
{
	if (!m)
		return ;
	for(int i = 0; i < INVENTORY_SIZE; i++)
	{
		if(this->_inventory[i] == 0)
		{
			this->_inventory[i] = m->clone();
			return;
		}
	}
}
//unequip
void Character::unequip(int idx)
{
	if(idx <= INVENTORY_SIZE)
		this->_inventory[idx] = 0;
	else 
		std::cout << "Index must be less or equal than 3" << std::endl;
}
//use
void Character::use(int idx, ICharacter& target)
{
	ICharacter *ptr = &target;
	if (!ptr)
		return ;
	if(idx > INVENTORY_SIZE)
	{
		std::cout << "The inventory capacity is 4, choose an index between 0-3" << std::endl;
		return;
	}
	if(this->_inventory[idx] != 0)
		this->_inventory[idx]->use(target);
	else 
	{
		std::cout << "Empty slot at index " << idx << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Character& value)
{
	return(os << value._inventory[0]);
}
