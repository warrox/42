/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:20:45 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/08 16:20:02 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP
#pragma once
#include "Animal.hpp"
#include "Brain.hpp"
class Dog : public Animal 
{
	private :
		Brain *b;

	public:
		Dog();
		Dog(Dog&);
		~Dog();
		Dog& operator=(Dog &);
		virtual void makeSound()const;
};
#endif // !DEBUG
