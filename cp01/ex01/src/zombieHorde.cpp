
#include "../includes/Zombie.hpp"
#include <cstdio>

// class PhoneBook
// {
// public:
//     PhoneBook(void);
//     ~PhoneBook(void);
//     void add(int index);
//     void search(void);
// 	void display_specific_contact(std::string command);
// private:
//     Contact _contacts[8];
//     int _index;
// };


Zombie* zombieHorde( int N, std::string name )
{
	Zombie* z = new Zombie[N];	
	//init zombie name
	for(int i = 0; i != N; ++i)
	{
		printf("yo\n");
		z[i].name = name;
		z[i].announce();
	}
	return(z);
}
