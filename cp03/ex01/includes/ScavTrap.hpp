/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:36:46 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/05 16:38:14 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	protected :
		std::string _name;
		int _HitPoints;
		int _EnergyPoints;
		int _AttackDamage;

	public :	
		void guardGate();	
		ScavTrap(std::string name);
		ScavTrap();
		void attack(const std::string& target);
		~ScavTrap();
};
