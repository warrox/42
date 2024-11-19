#include "ASpell.hpp"
#include "ATarget.hpp"

ASpell::ASpell(string name, string effects) :name(name), effects(effects) {
	return ;
}

ASpell::~ASpell() {
	return ;
}

string ASpell::getName(void) const  {
	return this->name;
}

ASpell &ASpell::operator=(ASpell const &rhs) {
	(void)rhs;
	return *this;
}

ASpell::ASpell(ASpell const &rhs) {
	(void)rhs;
	return ;
}

string ASpell::getEffects(void) const {
	return this->effects;
}

void ASpell::launch(const ATarget &target) const {
	target.getHitBySpell(*this);
}

