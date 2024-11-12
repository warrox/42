/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:24:16 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/12 16:45:38 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"


Character::Character(){};
Character::Character(std::string type) : _type(type)
{
	
}

Character::~Character(){}

Character::Character(const Character &other)
{
	*this = other;
}

Character & Character::operator=(const Character &other)
{
	if(this != &other)
	{
		this->_type = other._type;
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

}
//unequip
void Character::unequip(int idx)
{

}
//use
void Character::use(int idx, ICharacter& target)
{

}
