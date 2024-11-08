
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
		this->_ideas = new Animal;
		for(int i = 0; i <= 100;i++)
		{
			this->_ideas[i] = other._ideas[i];
		}
	}
	return(*this);
}

Brain::~Brain()
{
	std::cout<<"Brain Destructor called"<<std::endl;
	delete this->_ideas;
}
