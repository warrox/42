/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:50:30 by whamdi            #+#    #+#             */
/*   Updated: 2024/10/18 15:05:55 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"
#include <cstdio>
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

void Harl::complain(std::string level)
{
    alert funcs[] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
    std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };

    int level_index = -1;
    for (int i = 0; i < 4; i++) {
        if (levels[i] == level) {
            level_index = i;
            break;
        }
    }

    switch (level_index) {
		case 0:
			(this->*funcs[0])();
        case 1:
            (this->*funcs[1])();
        case 2:
            (this->*funcs[2])();
        case 3:
            (this->*funcs[3])();
            break;
        default:
            std::cout << "Invalid log level!" << std::endl;
    }
}
Harl::Harl(){};
Harl::~Harl(){};
//---------------------


