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
		Weapon(const std::string str);
		Weapon();
		~Weapon();
		void setType(const std::string &value);
};

#endif // DEBUG
