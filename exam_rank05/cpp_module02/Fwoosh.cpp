#include "Fwoosh.hpp"
#include "ATarget.hpp"
#include "ASpell.hpp"

Fwoosh::~Fwoosh() {
	return ;
}

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed") {
	return ;
}

Fwoosh *Fwoosh::clone(void) const {
	return new Fwoosh();
}

Fwoosh &Fwoosh::operator=(Fwoosh const &rhs) {
	(void)rhs;
	return *this;
}

Fwoosh::Fwoosh(Fwoosh const &rhs) : ASpell("Fwoosh", "fwooshed") {
	(void)rhs;
	return ;
}
