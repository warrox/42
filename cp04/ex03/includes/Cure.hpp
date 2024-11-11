
#ifndef CURE_HPP
#define CURE_HPP
#include "AMateria.hpp"

class Cure : public AMateria
{
	protected:
	
	public:
		Cure();
		~Cure();
		Cure(const Cure &);
		Cure & operator=(Cure &);
		virtual AMateria * clone()const;
};
#endif 
