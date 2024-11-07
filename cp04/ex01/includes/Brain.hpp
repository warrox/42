
#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <vector>
#include <iostream> 
class Brain{
	protected:
		std::vector<std::string> _ideas[100];
	public : 
		Brain();
		Brain(Brain &);
		Brain& operator=(Brain &);
		~Brain();
		
};


#endif // !BRAIN_HPP
