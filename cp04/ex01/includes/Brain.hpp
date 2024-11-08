
#ifndef BRAIN_HPP
#define BRAIN_HPP
#include "Animal.hpp"
#include <iostream> 
class Brain{
	protected:
		Animal * _ideas;
	public : 
		Brain();
		Brain(Brain &);
		Brain& operator=(Brain &);
		~Brain();
		
};


#endif // !BRAIN_HPP
