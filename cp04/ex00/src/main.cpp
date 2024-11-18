/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:23:45 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/14 14:15:16 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include <iostream>
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"
int main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal *wrongMeta = new WrongCat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << wrongMeta->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	wrongMeta->makeSound();
	delete meta;
	delete j;
	delete i;
	delete wrongMeta;
	return (0);
}
