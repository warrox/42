#include "HumanB.hpp"
#include <iostream>
#include <ostream>
#include <cstdio>
void HumanB::attack(void)
{
	std::cout << this->name << " attacks with their "; 
	std::cout << this->weapon->getType() << std::endl;

}
void HumanB::setWeapon(Weapon &weapon){
	this->weapon = &weapon;
}
HumanB::HumanB(const std::string &name) {
	this->name = name;
}
