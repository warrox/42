/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:22:01 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/14 11:31:26 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat() 
{
	this->_type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(Cat &other)
{
	*this = other;
}

Cat::~Cat()
{
	std::cout << "Cat  destroyed" << std::endl;
}

Cat&  Cat::operator=(Cat &other)
{
	if(this != &other){
		this->_type = other._type;
	}
	return(*this);
}
void Cat::makeSound() const
{
	std::cout << "Meow Meow ..." << std::endl;
}
