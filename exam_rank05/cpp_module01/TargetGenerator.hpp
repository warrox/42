#ifndef TARGETGENERATOR_H
# define TARGETGENERATOR_H

#include "ATarget.hpp"
class TargetGenerator {
	private:
		ATarget *targetBook[100];

	public:
		TargetGenerator();
		~TargetGenerator();	
		void learnTargetType(ATarget *target);
		void forgetTargetType(string const &type);
		ATarget *createTarget(string const &type) const;
};

#endif // !DEBUG
