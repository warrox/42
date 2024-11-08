/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:38:27 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/08 13:01:04 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog() 
{
	this->_type = "Dog";
	this->b = new Brain();
}

Dog::Dog(Dog &other)
{
	this->b = new Brain;
	*this->b = *(other.b);
}

Dog::~Dog()
{
	std::cout << "Dog  destroyed" << std::endl;
	delete b;
}

Dog&  Dog::operator=(Dog &other)
{
	if(this != &other){
		this->_type = other._type;
	}
	return(*this);
}

void Dog::makeSound()const
{
	std::cout << "Barkle Barkle ..." << std::endl;
}
