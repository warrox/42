#include "../includes/Zombie.hpp"

Zombie* Zombie::newZombie( std::string name )
{
	Zombie* z = new Zombie(name);

	return(z);
}

Zombie::Zombie(std::string name)
{
	_name = name;
}

Zombie::~Zombie()
{
	std::cout << "Destructor"<< std::endl;
}
