/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:43:15 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/13 18:54:23 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"

Cure::Cure()
{
    std::cout << "Cure constructor called" << std::endl;
    this->_type = "cure";
}
Cure::~Cure()
{
	std::cout << "Cure Desctructor called" << std::endl;
}

Cure::Cure(const Cure &other)
{
    *this = other;
}

Cure& Cure::operator=(const Cure &other)
{
    if (this != &other)
    {
        this->_type = other._type;
    }
    return *this;
}

AMateria* Cure::clone() const
{
    return (new Cure(*this));
}

void Cure::use(ICharacter & target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

