#include "Fireball.hpp"
#include "ATarget.hpp"
#include "ASpell.hpp"

Fireball::~Fireball() {
	return ;
}

Fireball::Fireball() : ASpell("Fireball", "burnt to a crisp") {
	return ;
}

Fireball *Fireball::clone(void) const {
	return new Fireball();
}

Fireball &Fireball::operator=(Fireball const &rhs) {
	(void)rhs;
	return *this;
}

Fireball::Fireball(Fireball const &rhs) : ASpell("Fireball", "burnt to a crisp") {
	(void)rhs;
	return ;
}
