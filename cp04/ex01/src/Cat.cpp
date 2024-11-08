/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:22:01 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/08 15:45:38 by whamdi           ###   ########.fr       */
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

void Cat::addIdea(std::string idea)
{
	static int index = 0;
	if (index >= 0 && index < 100) {
        this->b->_ideas[index] = idea;	
	}
}
std::string Cat::getIdea()
{
	return(this->b->_ideas[0]);
}
std::ostream &operator<<(std::ostream &ostream, Cat &self) {
	ostream << self.getIdea();
	return ostream;
}
