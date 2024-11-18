#include "ASpell.hpp"
#include "Fwoosh.hpp"
Fwoosh::Fwoosh()
{
	this->_name = "Fwoosh";
	this->_effects = "fwooshed";
};
Fwoosh::~Fwoosh(){};
Fwoosh::Fwoosh(Fwoosh & other)
{
	if(this != &other)
	{
		*this = other;
	}
}

Fwoosh & Fwoosh::operator=(Fwoosh &other)
{
	if(this != &other)
	{
		this->_name = other._name;
		this->_effects = other._effects;
	}
	return(*this);
}

ASpell* Fwoosh::clone()const
{
	return(new Fwoosh());
}
// const std::string Fwoosh::getName()const
// {
// 	return(this->getName());
// }


// const std::string Fwoosh::getEffects()const
// {
// 	return(this->_effects);
// }

// void Fwoosh::launch(ATarget const &other)const
// {
// 	other.getHitBySpell(*this);	
// }
