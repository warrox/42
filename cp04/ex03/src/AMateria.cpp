#include "../includes/AMateria.hpp"

AMateria::AMateria(std::string const & type)
{
	std::cout << "Materia Constructor called" << std::endl;	
}

AMateria::AMateria(AMateria &other)
{
	*this = other;
}

AMateria& AMateria::operator=(AMateria &other)
{
	//copy
	return(*this = other);
}
AMateria::~AMateria()
{
	std::cout << "Desctructor AMateria called" << std::endl;
}

