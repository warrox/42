#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <cstdio>
#include <string>
#include <iostream>
class Weapon
{
	private:
		std::string _type;
	public:
		const std::string& getType();
		void setType(const std::string &value);
		Weapon(const std::string str);
		Weapon();
		~Weapon();
};

#endif // DEBUG
