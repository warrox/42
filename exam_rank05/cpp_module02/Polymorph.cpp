#include "Polymorph.hpp"
#include "ATarget.hpp"
#include "ASpell.hpp"

Polymorph::~Polymorph() {
	return ;
}

Polymorph::Polymorph() : ASpell("Polymorph", "turned into a critter") {
	return ;
}

Polymorph *Polymorph::clone(void) const {
	return new Polymorph();
}

Polymorph &Polymorph::operator=(Polymorph const &rhs) {
	(void)rhs;
	return *this;
}

Polymorph::Polymorph(Polymorph const &rhs) : ASpell("Polymorph", "turned into a critter") {
	(void)rhs;
	return ;
}
