#ifndef HUMANB_HPP
#define HUMANB_HPP
#include "../includes/Weapon.hpp"
#include <string>
#include <ostream>
class HumanB
{
	public :
		HumanB(const std::string &name);
		void	attack(void);	
		void setWeapon(Weapon &weapon);
	private :
		Weapon *weapon;
		std::string name;
};
#endif
