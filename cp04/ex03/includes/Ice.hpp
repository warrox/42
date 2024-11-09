
#include "AMateria.hpp"

class Ice : public AMateria
{
	protected:
		std::string _type;	
	public:
		Ice();
		~Ice();
		Ice(Ice &);
		Ice & operator=(Ice &);
};
