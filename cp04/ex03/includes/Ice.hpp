
#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

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
};
#endif // !ICE_HPP
