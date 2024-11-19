#include "ATarget.hpp"
#include "ASpell.hpp"

ATarget::ATarget(string type) :type(type) {
	return ;
}

ATarget::~ATarget() {
	return ;
}

const string &ATarget::getType(void) const  {
	return this->type;
}

ATarget &ATarget::operator=(ATarget const &rhs) {
	(void)rhs;
	return *this;
}

ATarget::ATarget(ATarget const &rhs) {
	(void)rhs;
	return ;
}

void ATarget::getHitBySpell(ASpell const &spell) const {
	std::cout << this->getType() << " has been " << spell.getEffects() << "!" << std::endl;
}
