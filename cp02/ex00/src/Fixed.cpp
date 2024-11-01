/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:09:25 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/01 10:05:50 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include <iostream>

const int Fixed::_fractional_b = 8;

Fixed::Fixed() : _value(0){
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout <<"Copy assignment operator called" << std::endl;
	if(this != &other)
	{
		this->_value = other.getRawBits();
	}
	return *this;
}

int Fixed::getRawBits(void)const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(this->_value);
}
void Fixed::setRawbits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

Fixed::~Fixed()
{
	std::cout <<"Destructor called" << std::endl;
};
