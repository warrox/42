#include "Dummy.hpp"
#include "ATarget.hpp"

Dummy::~Dummy() {
	return ;
}

Dummy::Dummy() : ATarget("Target Practice Dummy") {
	return ;
}

Dummy *Dummy::clone(void) const {
	return new Dummy();
}

Dummy &Dummy::operator=(Dummy const &rhs) {
	(void)rhs;
	return *this;
}

Dummy::Dummy(Dummy const &rhs) : ATarget("Target Practice Dummy") {
	(void)rhs;
	return ;
}
