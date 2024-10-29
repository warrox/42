#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "../includes/Weapon.hpp"
#include <string>
#include <ostream>
class HumanA
{
	public :
		HumanA(const std::string &name, Weapon &weapon);
		void	attack(void);	
		~HumanA();
	private :
		Weapon *weapon;
		std::string _name;
};
#endif
