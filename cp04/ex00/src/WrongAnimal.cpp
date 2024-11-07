/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:54:39 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/07 20:25:49 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

	WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	
}
WrongAnimal::WrongAnimal(WrongAnimal &other)
{
	*this = other;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal  destroyed" << std::endl;
}

WrongAnimal&  WrongAnimal::operator=(WrongAnimal &other)
{
	if(this != &other){
		this->_type = other._type;
	}
	return(*this);
}

void WrongAnimal::makeSound()const
{
	std::cout << "Sound of a fake animal ..." << std::endl;
}

std::string WrongAnimal::getType()const
{
	return(this->_type);
}
