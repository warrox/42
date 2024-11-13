/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:45:40 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/13 19:01:09 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/MateriaSource.hpp"
#include <cstdio>

MateriaSource::MateriaSource()
{
	std::cout << "Materia Source called" << std::endl;
	for (int i = 0; i <= 3; i++)
	{
		this->_m[i] = 0;
	}
}

MateriaSource::~MateriaSource()
{
	std::cout << "Destructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria* other) {
    for (int i = 0; i <= 3; i++) {
        if (this->_m[i] == 0) {
            this->_m[i] = other->clone();
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(const std::string& type) {
    for (int i = 0; i <= 3; i++) {

		if (this->_m[i] != 0 && this->_m[i]->getType() == type) {
            return this->_m[i]->clone();
        }
    } 
	std::cout << "No Materia found of type: " << type << std::endl;
    return 0;
}
