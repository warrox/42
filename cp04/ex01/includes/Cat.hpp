/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:22:06 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/14 13:25:10 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP
#include <cstddef>
#pragma once
#include "Animal.hpp"
#include "Brain.hpp"
class Cat : public Animal 
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
		std::string getIdea(size_t idx);
};

std::ostream &operator<<(std::ostream &ostream, Cat &self);

#endif // !DEBUG
