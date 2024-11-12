
#include "../includes/Ice.hpp"

Ice::Ice()
{
    std::cout << "Ice constructor called" << std::endl;
    this->_type = "cure";
}

Ice::Ice(const Ice &other)
{
    *this = other;
}

Ice& Ice::operator=(const Ice &other)
{
    if (this != &other)
    {
        this->_type = other._type;
    }
    return *this;
}

AMateria* Ice::clone() const
{
    return (new Ice(*this));
}

void Ice::use(ICharacter & target)
{
    std::cout << " * shoots an ice bolt at  " << target.getName() << std::endl;
}

Ice::~Ice()
{
	std::cout << "Destructor called" << std::endl;
}
