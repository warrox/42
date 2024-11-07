/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:42:45 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/07 15:00:21 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include "iostream"
class Animal
{
	protected:
		std::string _type;
	
	public:
		Animal();
		Animal(Animal&);
		virtual ~Animal();
		Animal& operator=(Animal &);
		virtual	void  makeSound()const;
		std::string getType()const;
};
#endif // !DEBUG 



