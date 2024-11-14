/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:18:21 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/14 11:30:13 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "Animal constructor called" << std::endl;
}
Animal::Animal(Animal &other)
{
	*this = other;
}

Animal::~Animal()
{
	std::cout << "Animal  destroyed" << std::endl;
}

Animal&  Animal::operator=(Animal &other)
{
	if(this != &other){
		this->_type = other._type;
	}
	return(*this);
}

void Animal::makeSound()const
{
	std::cout << "Sound of an animal ..." << std::endl;
}

std::string Animal::getType()const
{
	return(this->_type);
}
