#ifndef WARLOCK_H
# define WARLOCK_H

#include "SpellBook.hpp"
#include <string>
#include <iostream>

typedef std::string string;

#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock {
	public: 
		Warlock(string name, string title);
		~Warlock();

		string getName(void) const;
		string getTitle(void) const;
		void   introduce(void) const;
		void   setTitle(string const &title);
		
		void   learnSpell(ASpell *spell);
		void   forgetSpell(string const &name);
		void   launchSpell(string const &name, ATarget const &target) const;

	private:
		string name;
		string title;
		SpellBook book;

};

#endif // DEBUG
