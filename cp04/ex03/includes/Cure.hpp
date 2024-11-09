

#include "AMateria.hpp"

class Cure : public AMateria
{
	protected:
	
	public:
		Cure();
		~Cure();
		Cure(Cure &);
		Cure & operator=(Cure &);
};
