/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:18:21 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/08 16:50:11 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AAnimal.hpp"

	AAnimal::AAnimal() : _type("AAnimal")
{
	
}
AAnimal::AAnimal(AAnimal &other)
{
	*this = other;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal  destroyed" << std::endl;
}

AAnimal&  AAnimal::operator=(AAnimal &other)
{
	if(this != &other){
		this->_type = other._type;
	}
	return(*this);
}

void AAnimal::makeSound()const
{
	std::cout << "Sound of an animal ..." << std::endl;
}

std::string AAnimal::getType()const
{
	return(this->_type);
}

