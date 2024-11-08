
#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream> 
class Brain{
	public : 
		static const int _Max_Ideas = 100;
		std::string  _ideas[_Max_Ideas];
		Brain();
		Brain(Brain &);
		Brain& operator=(Brain &);
		~Brain();
		
};


#endif // !BRAIN_HPP
