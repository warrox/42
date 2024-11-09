
#include "../includes/Ice.hpp"
#include "../includes/AMateria.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(Ice &other) : AMateria("ice")
{

}

Ice& Ice::operator=(Ice &other)
{

}
