/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:49:39 by whamdi            #+#    #+#             */
/*   Updated: 2024/10/18 14:13:57 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"


void Zombie::announce(void)
{
	std::cout << this->_name << " : ";
	std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}



