/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:22:01 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/14 13:48:02 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"
#include "../includes/colors.hpp"
#include <cstddef>
Cat::Cat() 
{
	this->_type = "Cat";
	this->b = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(Cat &other) : Animal(other)
{
	this->b = new Brain();
	*this->b = *(other.b);
}

Cat::~Cat()
{
	std::cout << GREEN << "Cat  destroyed" << RESET << std::endl;
	delete this->b;
}

Cat&  Cat::operator=(Cat &other)
{
	if(this != &other){
		this->_type = other._type;
		*(this->b) = *(other.b);
	}
	return(*this);
}
void Cat::makeSound() const
{
	std::cout << "Meow Meow ..." << std::endl;
}

void Cat::addIdea(std::string idea)
{
	size_t i;
	for (i = 0; i < 100 && this->b->_ideas[i].size(); i++) ;
	if (i == 100) return;
	this->b->_ideas[i] = idea;
}
std::string Cat::getIdea(size_t idx)
{
	return(this->b->_ideas[idx]);
}
std::ostream &operator<<(std::ostream &ostream, Cat &self) {
	for (size_t i = 0; i < 100; i++) {
		std::string idea = self.getIdea(i);
		if (idea.size() != 0)
			ostream << "ideas[" << i << "]:" << self.getIdea(i) << std::endl;
	}
	return ostream;
}
