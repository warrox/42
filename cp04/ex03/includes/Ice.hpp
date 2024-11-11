
#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
	protected:
		std::string _type;	
	public:
		Ice();
		~Ice();
		Ice(const Ice &);
		Ice & operator=(Ice &);
		virtual AMateria* clone() const;
		void use(ICharacter &);
};
#endif // !ICE_HPP
