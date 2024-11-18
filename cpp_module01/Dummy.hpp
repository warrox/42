#ifndef DUMMY_HPP
#define DUMMY_HPP
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <iostream>


class Dummy : public ATarget
{
	
	public:
		Dummy();
		Dummy(std::string attribute);
		~Dummy();
		Dummy(Dummy&);
		Dummy & operator=(Dummy &);
		const std::string getType()const;
		ATarget *clone()const;
		void getHitBySpell(const ASpell &)const;
};

#endif
