/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:09:25 by whamdi            #+#    #+#             */
/*   Updated: 2024/10/31 13:24:37 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include <iostream>

const int Fixed::_fractional_b = 8;

Fixed::Fixed() : _value(0){
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const int fixedPoint){
	this->_value = (fixedPoint << _fractional_b);
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _value(0)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const float fixedPoint){	
	std::cout << "Float constructor called" << std::endl;
	this->_value = int(roundf(fixedPoint * (1 << _fractional_b)));
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
	// std::cout << "getRawBits member function called" << std::endl;
	return(this->_value);
}

float Fixed::toFloat(void)const
{
	return float(this->_value) / (1 << _fractional_b);
}

int Fixed::toInt(void)const
{
	return this->_value >> _fractional_b;
}
Fixed::~Fixed()
{
	std::cout <<"Destructor called" << std::endl;
};


std::ostream &operator<<(std::ostream &ostream, const Fixed &self) {
	ostream << self.toFloat();
	return ostream;
}
