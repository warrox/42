#ifndef FIREBALL_H
# define FIREBALL_H

#include <string>
#include <iostream>

typedef std::string string;

class ATarget;

#include "ASpell.hpp"

class Fireball : public ASpell {
	public:
		void launch(ATarget const &target) const;
		Fireball();
		Fireball *clone(void) const;
		Fireball &operator=(Fireball const &rhs);
		Fireball(Fireball const &rhs);
		~Fireball();
};

#endif // !DEBUG
