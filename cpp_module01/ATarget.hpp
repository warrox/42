#pragma once
#include "ASpell.hpp"
#include <iostream>
class ASpell;

class ATarget
{
	protected:
		std::string _type;
	
	public:
		ATarget();
		ATarget(std::string attribute);
		~ATarget();
		ATarget(ATarget&);
		ATarget & operator=(ATarget &);
		const std::string getType()const;
		virtual ATarget *clone()const = 0;
		void getHitBySpell(const ASpell &)const;
};

