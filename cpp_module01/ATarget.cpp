#include "ATarget.hpp"
ATarget::ATarget(){};
ATarget::ATarget(std::string attribute) : _type(attribute)
{

}
ATarget::~ATarget(){};
ATarget::ATarget(ATarget & other)
{
	if(this != &other)
	{
		*this = other;
	}
}

ATarget & ATarget::operator=(ATarget &other)
{
	if(this != &other)
	{
		this->_type = other._type;
	}
	return(*this);
}

const std::string ATarget::getType()const
{
	return(this->getType());
}


void ATarget::getHitBySpell(const ASpell &spell)const
{
	std::cout <<this->_type<<" has been " <<spell.getEffects()<< "!" << std::endl; 
}
