#include "SpellBook.hpp"

SpellBook::SpellBook() {
	for (size_t i = 0; i < 100; i++)
	  this->spellBook[i] = 0;
	return ;
}

SpellBook::~SpellBook() {
	return ;
}

void SpellBook::learnSpell(ASpell *spell) {
	for (size_t i = 0; i < 100; i++) {
		if (!this->spellBook[i]) {
			this->spellBook[i] = spell;
			return ;
		}
	}
}

void SpellBook::forgetSpell(string const &name) {
	for (size_t i = 0; i < 100; i++) {
		if (this->spellBook[i] && name == this->spellBook[i]->getName()) {
			this->spellBook[i] = 0;
			return ;
		}
	}
}

ASpell *SpellBook::createSpell(string const &name) const {
	for (size_t i = 0; i < 100; i++) {
		if (this->spellBook[i] && name == this->spellBook[i]->getName()) {
			return this->spellBook[i]->clone();
		}
	}
	return 0;
}
