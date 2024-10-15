
#include "../includes/Weapon.hpp" 
#include <cstdio>
#include <iterator>
#include <string>

const std::string &Weapon::getType()
{
	return this->_type;
}
void Weapon::setType(const std::string &value)
{
	this->_type = value;
}

Weapon::Weapon(const std::string str){
	this->setType(str);
}

Weapon::Weapon(){
	this->setType("No Weapon");
}
Weapon::~Weapon(){}
