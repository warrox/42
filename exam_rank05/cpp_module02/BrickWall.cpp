#include "BrickWall.hpp"
#include "ATarget.hpp"

BrickWall::~BrickWall() {
	return ;
}

BrickWall::BrickWall() : ATarget("Inconspicuous Red-brick Wall") {
	return ;
}

BrickWall *BrickWall::clone(void) const {
	return new BrickWall();
}

BrickWall &BrickWall::operator=(BrickWall const &rhs) {
	(void)rhs;
	return *this;
}

BrickWall::BrickWall(BrickWall const &rhs) : ATarget("Inconspicuous Red-brick Wall") {
	(void)rhs;
	return ;
}
