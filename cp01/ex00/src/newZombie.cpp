#include "../includes/Zombie.hpp"

Zombie* newZombie( std::string name )
{
	Zombie* z = new Zombie;
	z->name = name;
	return(z);
}
