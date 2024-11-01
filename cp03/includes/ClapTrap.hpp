/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:42:53 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/01 10:45:49 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
class ClapTrap
{
	private :
		int _name;
		int _HitPoints;
		int _EnergyPoints;
		int _AttackDamage;
	public :
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};
