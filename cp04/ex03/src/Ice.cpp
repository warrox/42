
#include "../includes/Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria("ice")
{

}

Ice& Ice::operator=(Ice &other)
{

}

AMateria* Ice::clone()const
{
	return(new Ice(*this));
}
void Ice::use(ICharacter & target)
{

}
