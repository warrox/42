#ifndef FWOOSH_HPP
#define FWOOSH_HPP
#include <iostream>
#include "ASpell.hpp"
class Fwoosh : public ASpell
{
	// protected:
	// 	std::string _name;
	// 	std::string _effects;
	public:
		Fwoosh();
		Fwoosh(std::string name, std::string effects);
		virtual ~Fwoosh();
		Fwoosh(Fwoosh&);
		Fwoosh & operator=(Fwoosh &);
		const std::string getName()const;
		const std::string getEffects()const;
		ASpell *clone()const;
		void launch(ATarget const &other)const;
};

#endif
