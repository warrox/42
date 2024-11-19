#ifndef POLYMORPH_H
# define POLYMORPH_H

#include <string>
#include <iostream>

typedef std::string string;

class ATarget;

#include "ASpell.hpp"

class Polymorph : public ASpell {
	public:
		void launch(ATarget const &target) const;
		Polymorph();
		Polymorph *clone(void) const;
		Polymorph &operator=(Polymorph const &rhs);
		Polymorph(Polymorph const &rhs);
		~Polymorph();
};

#endif // !DEBUG
