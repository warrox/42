#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <cstdio>
#include <string>
class Weapon
{
	public:
		std::string type;
		const std::string *getType(std::string &type);
		std::string setType(std::string value);
};

#endif // DEBUG
