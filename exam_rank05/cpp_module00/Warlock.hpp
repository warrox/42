#ifndef WARLOCK_H
# define WARLOCK_H

#include <string>
#include <iostream>

typedef std::string string;

class Warlock {
	public: 
		Warlock(string name, string title);
		~Warlock();

		string getName(void) const;
		string getTitle(void) const;
		void   introduce(void) const;
		void   setTitle(string const &title);
		

	private:
		string name;
		string title;

};

#endif // DEBUG
