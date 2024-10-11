#include "HumanA.hpp"
#include <iostream>
#include <ostream>
#include <cstdio>
void HumanA::attack(void)
{
	const std::string *weap = this->weapon.getType(this->weapon.type);
	std::cout << this->name << "attacks with their"; 
	std::cout << weap << std::endl;
}
