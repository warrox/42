#ifndef DUMMY_H
# define DUMMY_H

#include <string>
#include <iostream>

typedef std::string string;

class ATarget;

#include "ATarget.hpp"

class Dummy : public ATarget {
	public:
		void launch(ATarget const &target) const;
		Dummy();
		Dummy *clone(void) const;
		Dummy &operator=(Dummy const &rhs);
		Dummy(Dummy const &rhs);
		~Dummy();
};

#endif // !DEBUG
