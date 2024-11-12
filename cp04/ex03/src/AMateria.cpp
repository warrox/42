#include "../includes/AMateria.hpp"

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

