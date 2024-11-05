/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:58:57 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/05 13:56:21 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FlagTrap.hpp"

int main(void)
{
	FlagTrap r;
	r.attack("baba");
	r.beRepaired(10);
	r.takeDamage(5);
	r.highFivesGuy();
	return(0);
}
