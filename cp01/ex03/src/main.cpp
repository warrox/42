/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:26:46 by whamdi            #+#    #+#             */
/*   Updated: 2024/10/15 11:45:22 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include <cstdio>

//
// int main(int argc, char **argv)
// {
// 	Weapon weapon;
// 	const std::string str = "Knife";
// 	const std::string name = "Warren";
// 	const std::string nameB = "Kirikou";
// 	weapon.setType(str);
// 	HumanA hmn(name,weapon);
// 	HumanB hmnB(nameB);
// 	hmn.attack();
// 	hmnB.attack();
// 	(void) argc, (void) argv;
//
// 	return(0);
// }
//
int main()
{
	Weapon club = Weapon("crude spiked club");
	HumanA bob("Bob", club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();
	HumanB jim("Jim");
	jim.attack();
	club.setType("crude spiked club");
	jim.setWeapon(club);
	jim.attack();
	club.setType("some other type of club");
	jim.attack();
	return 0;
}
