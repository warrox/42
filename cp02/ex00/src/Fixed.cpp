/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:09:25 by whamdi            #+#    #+#             */
/*   Updated: 2024/10/31 10:23:50 by whamdi           ###   ########.fr       */
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
	// this->_value = other.getRawBits();
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

Fixed::~Fixed()
{
	std::cout <<"Destructor called" << std::endl;
};
