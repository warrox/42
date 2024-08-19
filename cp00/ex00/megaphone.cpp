/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 13:43:00 by whamdi            #+#    #+#             */
/*   Updated: 2024/08/19 17:14:05 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char **argv) 
{
    if (argc > 1) 
	{
        for (int i = 1; i < argc; ++i) 
		{
            std::string txt = argv[i];
            for (std::string::size_type j = 0; j < txt.size(); ++j)
			{
                txt[j] = std::toupper(txt[j]);
            }
            std::cout << txt << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    return 0;
}
