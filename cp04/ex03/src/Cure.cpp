

#include "../includes/Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(const Cure &other) : AMateria("cure")
{

}

Cure& Cure::operator=(Cure &other)
{

}

AMateria* Cure::clone()const 
{
	return(new Cure(*this));
}

void Cure::use(ICharacter & target)
{

}
