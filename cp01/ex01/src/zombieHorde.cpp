
#include "../includes/Zombie.hpp"
#include <cstdio>
#include <iterator>

Zombie* zombieHorde( int N, std::string name )
{
	Zombie* z = new Zombie[N];	
	//init zombie name
	for(int i = 0; i != N; ++i)
	{
		z[i].name = name;
		std::cout << z[i].name << std::endl;
		z[i].announce();
	}
	return(z);
}
