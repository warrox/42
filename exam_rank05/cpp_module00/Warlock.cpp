#include "Warlock.hpp"

Warlock::Warlock(string name, string title) :name(name), title(title) {
	std::cout << this->name << ": This looks like another boring day." << std::endl;
	return ;
}

Warlock::~Warlock() {
	std::cout << this->name << ": My job here is done!" << std::endl;
	return ;
}

void Warlock::introduce(void) const {
	std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}

string Warlock::getName(void) const  {
	return this->name;
}

string Warlock::getTitle(void) const {
	return this->title;
}

void   Warlock::setTitle(string const &title) {
	this->title = title;
}
