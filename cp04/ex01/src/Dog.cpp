/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:38:27 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/09 09:19:06 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include "../includes/colors.hpp"
Dog::Dog() 
{
	this->_type = "Dog";
	this->b = new Brain();
}

Dog::Dog(Dog &other) : Animal(other)
{
	this->b = new Brain;
	*this->b = *(other.b);
}

Dog::~Dog()
{
	std::cout << GREEN << "Dog  destroyed" << RESET <<  std::endl;
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
