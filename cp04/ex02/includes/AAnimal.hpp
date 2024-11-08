/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:42:45 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/08 16:47:20 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>

class AAnimal
{
	protected:
		std::string _type;
	
	public:
		AAnimal();
		AAnimal(AAnimal&);
		virtual ~AAnimal();
		AAnimal& operator=(AAnimal &);
		virtual	void  makeSound()const = 0;
		std::string getType()const;
};

#include "Brain.hpp"
#endif // !DEBUG 



