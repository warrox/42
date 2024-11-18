
#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
	protected:
	public:
		Ice();
		Ice(const Ice &);
		Ice & operator=(const Ice &);
		AMateria* clone() const;
		void use(ICharacter & target);
		~Ice();
};
#endif // !ICE_HPP
