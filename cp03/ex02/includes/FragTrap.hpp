/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:46:21 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/05 17:15:19 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	protected :
		std::string _name;
		int _HitPoints;
		int _EnergyPoints;
		int _AttackDamage;

	public :	
		void guardGate();	
		FragTrap(std::string name);
		FragTrap();
		FragTrap(const FragTrap &);
		void highFivesGuys(void);
		FragTrap &operator=(const FragTrap&);
		void attack(const std::string& target);
		~FragTrap();

};
