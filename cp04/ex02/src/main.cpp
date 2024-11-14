/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:23:45 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/14 14:34:21 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AAnimal.hpp"
#include <cstdio>
#include <iostream>
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/colors.hpp"


int main()
{
	const AAnimal* j = new Dog();
	Cat* i = new Cat();
	Cat copy;

	copy = *i;
	
	i->addIdea("Dumb");
	delete j;//should not create a leak
	delete i;
	std::cout << RED<< "Type of copy :" << copy.getType() <<RESET<< std::endl;
	std::cout << "Brain from copy :" << copy.getIdea(0) << std::endl;
	copy.addIdea("Dumb");
	std::cout << "Brain :" << copy.getIdea(0) << std::endl;
	return(0);
}
