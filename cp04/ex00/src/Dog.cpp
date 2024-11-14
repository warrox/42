/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:38:27 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/14 11:31:52 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog() 
{
	this->_type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(Dog &other)
{
	*this = other;
}

Dog::~Dog()
{
	std::cout << "Dog  destroyed" << std::endl;
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
