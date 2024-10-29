
#include "../includes/Zombie.hpp"
#include <cstdio>

void Zombie::set_name(std::string name)
{
	this->_name = name;
}
Zombie* zombieHorde( int N, std::string name )
{
	Zombie* z = new Zombie[N];
	//init zombie name
	for(int i = 0; i != N; ++i)
		z[i].set_name(name);
	return(z);
}
