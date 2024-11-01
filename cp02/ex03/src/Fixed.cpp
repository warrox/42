/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:09:25 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/01 10:08:07 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include <iostream>

const int Fixed::_fractional_b = 8;

Fixed::Fixed() : _value(0){
	// std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const int fixedPoint){
	this->_value = (fixedPoint << _fractional_b);
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _value(0)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const float fixedPoint){	
	// std::cout << "Float constructor called" << std::endl;
	this->_value = int(roundf(fixedPoint * (1 << _fractional_b)));
}

Fixed& Fixed::operator=(const Fixed& other)
{
	// std::cout <<"Copy assignment operator called" << std::endl;
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

void Fixed::setRawbits(int const raw)
{
	this->_value = raw;
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
	// std::cout <<"Destructor called" << std::endl;
};


std::ostream &operator<<(std::ostream &ostream, const Fixed &self) {
	ostream << self.toFloat();
	return ostream;
}

bool	Fixed::operator>=(const Fixed &other)
{
	return(this->getRawBits() >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed&other)
{
	return(this->getRawBits() <= other.getRawBits());
}
bool Fixed::operator<(const Fixed&other)
{
	return(this->getRawBits() < other.getRawBits());
}
bool Fixed::operator>(const Fixed&other)
{
	return(this->getRawBits() > other.getRawBits());
}
bool Fixed::operator!=(const Fixed&other)
{
	return(this->getRawBits() > other.getRawBits());
}
bool Fixed::operator==(const Fixed&other)
{
	return(this->getRawBits() == other.getRawBits());
}



float Fixed::operator+(const Fixed&other)
{
	return(this->toFloat() + other.toFloat());
}
float Fixed::operator-(const Fixed&other)
{
	return(this->toFloat() - other.toFloat());
}
float Fixed::operator*(const Fixed&other)
{
	return(this->toFloat() * other.toFloat());
}
float Fixed::operator/(const Fixed&other)
{
	return(this->toFloat() / other.toFloat());
}


Fixed Fixed::operator++()
{
	this->_value++;
	return(*this);
}

Fixed Fixed::operator--()
{
	this->_value--;
	return(*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	++this->_value;
	return(tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	--this->_value;
	return(tmp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if(a.toFloat() >= b.toFloat())
		return(b);
	else
		return(a);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if(a.toFloat() >= b.toFloat())
		return(b);
	else
		return(a);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if(a.toFloat() >= b.toFloat())
		return(a);
	else
		return(b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if(a.toFloat() >= b.toFloat())
		return(a);
	else
		return(b);
}
