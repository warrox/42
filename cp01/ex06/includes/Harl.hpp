/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:45:44 by whamdi            #+#    #+#             */
/*   Updated: 2024/10/16 14:53:40 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <cstddef>
#include <cstdio>
#include <string>

class Harl
{
	private :
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
	public :
		Harl();
		void complain(std::string level);
		~Harl();
};
#endif
