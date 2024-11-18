#ifndef WARLOCK_HPP
#define WARLOCK_HPP
#include <iostream>
#include "ASpell.hpp"

class Warlock
{
	private:
		std::string _name;
		std::string _title;
		ASpell *spellBook[100];
	
	public:
		Warlock();
		Warlock(std::string name, std::string title);
		~Warlock();
		Warlock(Warlock&);
		Warlock & operator=(Warlock &);
		const std::string getName()const;
		const std::string getTitle()const;
		void setTitle(const std::string &new_title);
		void introduce() const;
		void learnSpell(ASpell *);
		void forgetSpell(std::string spell_name);
		void launchSpell(std::string spell_name, ATarget&);
};

#endif
