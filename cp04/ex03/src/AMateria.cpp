#include "../includes/AMateria.hpp"
#include <cstdio>

AMateria::AMateria()
{
	std::cout << "Materia Constructor called" << std::endl;	
}

AMateria::AMateria(AMateria &other)
{
	*this=other;
}

AMateria& AMateria::operator=(AMateria &other)
{
	if (this != &other)
    {
		this->_type = other._type;
    }
    return *this;
}
AMateria::~AMateria()
{
	std::cout << "Desctructor AMateria called" << std::endl;
}

void AMateria::use(ICharacter& target) {
    std::cout << "AMateria used on " << target.getName() << std::endl;
}


std::string const & AMateria::getType() const
{
	return(this->_type);
}

