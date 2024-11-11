
#ifndef CURE_HPP
#define CURE_HPP
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
	protected:
	
	public:
		Cure();
		~Cure();
		Cure(const Cure &);
		Cure & operator=(Cure &);
		virtual AMateria * clone()const;
		virtual void use(ICharacter& target); 
};
#endif 
