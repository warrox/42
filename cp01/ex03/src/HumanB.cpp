#include "HumanB.hpp"
#include <iostream>
#include <ostream>
#include <cstdio>
void HumanB::attack(void)
{
	const std::string &weap = this->weapon.getType();
	std::cout << this->name << " attacks with their "; 
	std::cout << weap << std::endl;
}

HumanB::HumanB(const std::string &name) {
	this->name = name;
}
