#ifndef FWOOSH_H
# define FWOOSH_H

#include <string>
#include <iostream>

typedef std::string string;

class ATarget;

#include "ASpell.hpp"

class Fwoosh : public ASpell {
	public:
		void launch(ATarget const &target) const;
		Fwoosh();
		Fwoosh *clone(void) const;
		Fwoosh &operator=(Fwoosh const &rhs);
		Fwoosh(Fwoosh const &rhs);
		~Fwoosh();
};

#endif // !DEBUG
