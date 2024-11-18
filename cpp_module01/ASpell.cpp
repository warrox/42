#include "ASpell.hpp"
ASpell::ASpell(){};

ASpell::ASpell(std::string name, std::string effects) : _name(name), _effects(effects)
{

}
ASpell::~ASpell(){};
ASpell::ASpell(ASpell & other)
{
	if(this != &other)
	{
		*this = other;
	}
}

ASpell & ASpell::operator=(ASpell &other)
{
	if(this != &other)
	{
		this->_name = other._name;
		this->_effects = other._effects;
	}
	return(*this);
}

const std::string ASpell::getName()const
{
	return(this->getName());
}


const std::string ASpell::getEffects()const
{
	return(this->_effects);
}

void ASpell::launch(ATarget const &other)const
{
	other.getHitBySpell(*this);	
}
