#ifndef BRICKWALL_H
# define BRICKWALL_H

#include <string>
#include <iostream>

typedef std::string string;

class ATarget;

#include "ATarget.hpp"

class BrickWall : public ATarget {
	public:
		void launch(ATarget const &target) const;
		BrickWall();
		BrickWall *clone(void) const;
		BrickWall &operator=(BrickWall const &rhs);
		BrickWall(BrickWall const &rhs);
		~BrickWall();
};

#endif // !DEBUG
