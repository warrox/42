/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:43:15 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/14 11:21:59 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <iostream>
class WrongAnimal
{
	protected:
		std::string _type;
	
	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal&);
		~WrongAnimal();
		WrongAnimal& operator=(WrongAnimal &);
		void  makeSound()const;
		std::string getType()const;
};
#endif // !DEBUG 

