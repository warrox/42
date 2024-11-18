// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   Dog.cpp                                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/11/07 13:38:27 by whamdi            #+#    #+#             */
// /*   Updated: 2024/11/14 11:33:22 by whamdi           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */
//
// #include "../includes/Dog.hpp"
// #include "../includes/colors.hpp"
// Dog::Dog() 
// {
// 	this->_type = "Dog";
// 	this->b = new Brain();
// 	std::cout << "Dog constructor called" << std::endl;
// }
//
// Dog::Dog(Dog &other) : Animal(other)
// {
// 	this->b = new Brain;
// 	*this->b = *(other.b);
// }
//
// Dog::~Dog()
// {
// 	std::cout << GREEN << "Dog  destroyed" << RESET <<  std::endl;
// 	delete b;
// }
//
// Dog&  Dog::operator=(Dog &other)
// {
// 	if(this != &other){
// 		this->_type = other._type;
// 		this->b = new Brain();
// 		*this->b = *(other.b);
// 	}
// 	return(*this);
// }
//
// void Dog::makeSound()const
// {
// 	std::cout << "Barkle Barkle ..." << std::endl;
// }



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:22:01 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/14 13:48:02 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include "../includes/colors.hpp"
#include <cstddef>
Dog::Dog() 
{
	this->_type = "Dog";
	this->b = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(Dog &other) : Animal(other)
{
	this->b = new Brain();
	*this->b = *(other.b);
}

Dog::~Dog()
{
	std::cout << GREEN << "Dog  destroyed" << RESET << std::endl;
	delete this->b;
}

Dog&  Dog::operator=(Dog &other)
{
	if(this != &other){
		this->_type = other._type;
		*(this->b) = *(other.b);
	}
	return(*this);
}
void Dog::makeSound() const
{
	std::cout << "Barkle Barkle ..." << std::endl;
}

void Dog::addIdea(std::string idea)
{
	size_t i;
	for (i = 0; i < 100 && this->b->_ideas[i].size(); i++) ;
	if (i == 100) return;
	this->b->_ideas[i] = idea;
}
std::string Dog::getIdea(size_t idx)
{
	return(this->b->_ideas[idx]);
}
std::ostream &operator<<(std::ostream &ostream, Dog &self) {
	for (size_t i = 0; i < 100; i++) {
		std::string idea = self.getIdea(i);
		if (idea.size() != 0)
			ostream << "ideas[" << i << "]:" << self.getIdea(i) << std::endl;
	}
	return ostream;
}
