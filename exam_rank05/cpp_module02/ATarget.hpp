#ifndef ATARGET_H
# define ATARGET_H

#include <string>
#include <iostream>

typedef std::string string;

class ASpell;

class ATarget {
	public:
		const string &getType(void) const;
		void getHitBySpell(ASpell const &spell) const;
		ATarget(string type);
		virtual ATarget *clone(void) const = 0;
		ATarget &operator=(ATarget const &rhs);
		ATarget(ATarget const &rhs);
		virtual ~ATarget();
		
	private:
		string type;
		
};

#endif // !DEBUG
