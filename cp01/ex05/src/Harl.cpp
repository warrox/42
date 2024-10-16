/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:50:30 by whamdi            #+#    #+#             */
/*   Updated: 2024/10/16 13:39:51 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"
#include <iostream>
#include <sys/cdefs.h>


void Harl::debug(void)
{
	std::cout<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !" << std::endl;
}
	void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}
	void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}
	void Harl::error(void)
{
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}

typedef void (Harl::*alert)(void);
#define ARRAY_SIZE(arr) sizeof(arr) / sizeof(arr[0])

void Harl::complain(std::string level )
{
	static const struct {
		std::string level;
		alert func;
	} map[] = {
		{"DEBUG", &Harl::debug },
		{"INFO", &Harl::info },
		{"WARNING", &Harl::warning },
		{"ERROR", &Harl::error },
	};

	for (size_t i = 0; i < ARRAY_SIZE(map); i++) {
		if (level == map[i].level) {
			(this->*map[i].func)();
		}
	}
}
Harl::Harl(){};
Harl::~Harl(){};
