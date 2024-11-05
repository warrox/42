/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:58:57 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/05 14:15:12 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

int main(void)
{
	ClapTrap r("bob");
	r.attack("baba");
	r.beRepaired(10);
	r.takeDamage(5);
	// std::cout << r << std::endl;
	return(0);
}
