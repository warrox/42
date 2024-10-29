/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:30:26 by whamdi            #+#    #+#             */
/*   Updated: 2024/10/29 14:40:58 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"
#include <iostream>
int main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cout << "enter one arg <ALERT>" << std::endl;
		return(-1);
	}
	Harl h;
	
	std::string string = argv[1];
	h.complain(string);
	return(0);
}
