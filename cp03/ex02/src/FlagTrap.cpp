/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:06:54 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/05 13:56:44 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FlagTrap.hpp"

FlagTrap::FlagTrap(): ClapTrap("Scap's parent") 
{
	std::cout << "Constructor called for FlagTrap" << std::endl;
}

FlagTrap::~FlagTrap()
{
	std::cout << "Destroy FlagTrap" << std::endl;
}

void FlagTrap::highFivesGuy()
{
	std::cout << "FlagTrap :  Do you want a High Five bro ? " << std::endl;
}

