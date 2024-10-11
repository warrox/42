#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "../includes/Weapon.hpp"
#include <string>
#include <ostream>
class HumanA
{
	public :
		Weapon weapon;
		std::string name;
	private :
	void	attack(void);	
};
#endif
