#include "Dummy.hpp"
Dummy::Dummy()
{
	this->_type = "Target Practice Dummy";
};
Dummy::~Dummy(){};
Dummy::Dummy(Dummy & other)
{
	if(this != &other)
	{
		*this = other;
	}
}

Dummy & Dummy::operator=(Dummy &other)
{
	if(this != &other)
	{
		this->_type = other._type;
	}
	return(*this);
}

// const std::string Dummy::getType()const
// {
// 	return(this->getType());
// }


// void Dummy::getHitBySpell(const ASpell &spell)const
// {
// 	std::cout <<this->_type<<" has been " <<spell.getEffects()<< "!" << std::endl; 
// }
ATarget* Dummy::clone()const
{
	return(new Dummy());
}

