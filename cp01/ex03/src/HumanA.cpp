#include "HumanA.hpp"
#include <iostream>
#include <ostream>
#include <cstdio>
void HumanA::attack(void)
{
	std::cout << this->name << " attacks with their "; 
	std::cout << this->weapon->getType() << std::endl;
	
}

HumanA::HumanA(const std::string &name, Weapon &weapon) {
	this->name = name;
	this->weapon = &weapon;
}

HumanA::~HumanA(){}
