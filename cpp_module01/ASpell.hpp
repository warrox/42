#pragma once
#include "ATarget.hpp"
#include <iostream>
class ATarget;

class ASpell
{
	protected:
		std::string _name;
		std::string _effects;
	
	public:
		ASpell();
		ASpell(std::string name, std::string effects);
		~ASpell();
		ASpell(ASpell&);
		ASpell & operator=(ASpell &);
		const std::string getName()const;
		const std::string getEffects()const;
		virtual ASpell *clone()const = 0;
		void launch(ATarget const &other)const;
};

