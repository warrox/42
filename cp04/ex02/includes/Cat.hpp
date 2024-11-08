/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:22:06 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/08 16:49:54 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP
#pragma once
#include "AAnimal.hpp"
#include "Brain.hpp"
class Cat : public AAnimal 
{
	private :
		Brain *b;
	public:
		Cat();
		Cat(Cat &);
		~Cat();
		Cat& operator=(Cat &);
		virtual void makeSound()const;
		void addIdea(std::string);
		std::string getIdea();
};
#endif // !DEBUG
