
#ifndef BRAIN_HPP
#define BRAIN_HPP
#include "Animal.hpp"
#include <iostream> 
class Brain{
	public : 
		std::string  _ideas[100];
		Brain();
		Brain(Brain &);
		Brain& operator=(Brain &);
		~Brain();
		
};


#endif // !BRAIN_HPP
