/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:22:01 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/08 12:59:28 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat() 
{
	this->_type = "Cat";
	this->b = new Brain();
}

Cat::Cat(Cat &other)
{
	this->b = new Brain();
	*this->b = *(other.b);


}

Cat::~Cat()
{
	std::cout << "Cat  destroyed" << std::endl;
	delete this->b;
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
