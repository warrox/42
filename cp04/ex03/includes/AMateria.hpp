
#pragma once
#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#include "ICharacter.hpp"
#include <iostream>
class AMateria
{
	protected:
	public:
			
		AMateria(std::string const & type);
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
		AMateria(AMateria&);
		AMateria & operator=(AMateria&);
		~AMateria();	
};
#endif // !AMATERIA_HPP
