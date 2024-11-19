#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {
	for (size_t i = 0; i < 100; i++)
	  this->targetBook[i] = 0;
	return ;
}

TargetGenerator::~TargetGenerator() {
	return ;
}

void TargetGenerator::learnTargetType(ATarget *spell) {
	for (size_t i = 0; i < 100; i++) {
		if (!this->targetBook[i]) {
			this->targetBook[i] = spell;
			return ;
		}
	}
}

void TargetGenerator::forgetTargetType(string const &name) {
	for (size_t i = 0; i < 100; i++) {
		if (this->targetBook[i] && name == this->targetBook[i]->getType()) {
			this->targetBook[i] = 0;
			return ;
		}
	}
}

ATarget *TargetGenerator::createTarget(string const &name) const {
	for (size_t i = 0; i < 100; i++) {
		if (this->targetBook[i] && name == this->targetBook[i]->getType()) {
			return this->targetBook[i]->clone();
		}
	}
	return 0;
}
