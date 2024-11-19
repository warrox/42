#ifndef ASPELL_H
# define ASPELL_H

#include <string>
#include <iostream>

typedef std::string string;

class ATarget;

class ASpell {
	public:
		string getName(void) const;
		string getEffects(void) const;
		void launch(ATarget const &target) const;
		ASpell(string name, string effects);
		virtual ASpell *clone(void) const = 0;
		ASpell &operator=(ASpell const &rhs);
		ASpell(ASpell const &rhs);
		virtual ~ASpell();
		
	protected:
		string name;
		string effects;
};

#endif // !DEBUG
