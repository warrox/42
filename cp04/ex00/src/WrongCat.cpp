/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:36:35 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/07 16:39:50 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() 
{
	this->_type = "WrongCat";
}

WrongCat::WrongCat(WrongCat &other)
{
	*this = other;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat  destroyed" << std::endl;
}

WrongCat&  WrongCat::operator=(WrongCat &other)
{
	if(this != &other){
		this->_type = other._type;
	}
	return(*this);
}
void WrongCat::makeSound() const
{
	std::cout << "Fake Meow Meow ..." << std::endl;
}
