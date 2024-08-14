/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 13:43:00 by whamdi            #+#    #+#             */
/*   Updated: 2024/08/14 14:48:36 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char **argv) 
{
    if (argc > 1) 
	{
        for (int i = 1; i < argc; ++i) 
		{
            std::string txt = argv[i];
            for (std::string::size_type j = 0; j < txt.size(); ++j)
			{
                if (txt[j] >= 'a' && txt[j] <= 'z') 
				{
                    txt[j] = txt[j] - 'a' + 'A';
                }
            }
            std::cout << txt << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    return 0;
}

