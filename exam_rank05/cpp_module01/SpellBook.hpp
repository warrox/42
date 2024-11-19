#ifndef SPELLBOOK_H
# define SPELLBOOK_H

#include "ASpell.hpp"
class SpellBook {
	private:
		ASpell *spellBook[100];

	public:
		SpellBook();
		~SpellBook();	
		void learnSpell(ASpell *spell);
		void forgetSpell(string const &name);
		ASpell *createSpell(string const &name) const;
};

#endif // !DEBUG
