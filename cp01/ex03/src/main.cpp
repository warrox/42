/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:26:46 by whamdi            #+#    #+#             */
/*   Updated: 2024/10/14 13:44:09 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include <cstdio>


int main(int argc, char **argv)
{
	Weapon weapon;
	const std::string str = "Knife";
	const std::string name = "Warren";
	const std::string nameB = "Kirikou";
	weapon.setType(str);
	HumanA hmn(name,weapon);
	HumanB hmnB(nameB);
	hmn.attack();
	hmnB.attack();
	(void) argc, (void) argv;

	return(0);
}
