/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:23:45 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/08 16:41:37 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include <cstdio>
#include <iostream>
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/colors.hpp"

// int main(void)
// {
// 	Animal *a[100];
// 	for(int i = 0; i <= 100; i++)
// 	{
// 		a[i] = new Dog;
// 		if(i == 100)
// 			break;
// 		a[i + 1] = new Cat;
// 		printf("i : %d\n", i);
// 		
// 		printf("i + 1  : %d\n", i + 1);
// 	}
// 	for (int i = 0; i < 100; i++)
// 	{
// 		delete a[i];
// 	}
// }
int main()
{
	const Animal* j = new Dog();
	Cat* i = new Cat();
	Cat copy;

	copy = *i;
	
	i->addIdea("Dumb");
	delete j;//should not create a leak
	delete i;
	std::cout << RED<< "Brain :" << copy.getType() <<RESET<< std::endl;
	std::cout << "Brain :" << copy.getIdea() << std::endl;
	copy.addIdea("Dumb");
	std::cout << "Brain :" << copy.getIdea() << std::endl;
	return(0);
}
