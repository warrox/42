/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:22:06 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/14 14:30:40 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP
#include <cstddef>
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
		std::string getIdea(size_t idx);
};

std::ostream &operator<<(std::ostream &ostream, Cat &self);

#endif // !DEBUG
