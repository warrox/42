
#include "../includes/Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Constructor called" << std::endl;
}

Brain::Brain(Brain &other)
{	
	*this = other;	
}

Brain& Brain::operator=(Brain &other)
{
	if(this != &other)
	{
		this->_ideas[100] = other._ideas[100];	
	}
	return(*this);
}

Brain::~Brain()
{
	std::cout<<"Brain Destructor called"<<std::endl;
}
