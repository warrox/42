/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:38:53 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/07 16:53:38 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#pragma once
#include "WrongAnimal.hpp"
class WrongCat : public WrongAnimal 
{

	public:
		WrongCat();
		WrongCat(WrongCat &);
		~WrongCat();
		WrongCat& operator=(WrongCat &);
		void makeSound()const;
};
#endif // !DEBUG
