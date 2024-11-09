

#include "../includes/Cure.hpp"
#include "../includes/AMateria.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(Cure &other) : AMateria("cure")
{

}

Cure& Cure::operator=(Cure &other)
{

}
