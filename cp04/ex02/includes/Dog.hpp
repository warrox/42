/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:20:45 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/08 16:49:36 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP
#pragma once
#include "AAnimal.hpp"
#include "Brain.hpp"
class Dog : public AAnimal 
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
