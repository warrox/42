/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:20:45 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/14 14:25:22 by whamdi           ###   ########.fr       */
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
		void addIdea(std::string);
		std::string getIdea(size_t idx);

};
#endif // !DEBUG
