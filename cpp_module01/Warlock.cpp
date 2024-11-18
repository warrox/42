#include "Warlock.hpp"

static int i = 0;
Warlock::Warlock(std::string name, std::string title): _name(name) , _title(title)
{
	std::cout << this->_name<<": This looks like another boring day."<< std::endl;
}
Warlock::Warlock(){}

Warlock::~Warlock()
{
	std::cout <<this->_name<<": My job here is done!"<<std::endl;
}

Warlock::Warlock(Warlock &other)
{
	if(this != &other)
	{
		*this = other;
	}
}

Warlock & Warlock::operator=(Warlock &other)
{
	if(this != &other)
	{
		this->_name = other._name;
		this->_title = other._title;
	}
	return(*this);
}
const std::string Warlock::getName()const
{
	return(this->_name);
}

const std::string Warlock::getTitle()const
{
	return(this->_title);
}


void Warlock::setTitle(const std::string &new_title)
{
	this->_title = new_title;
}
void Warlock::introduce() const
{
	std::cout <<this->_name<<": I am "<<this->_name<<", "<<this->_title<<"!"<<std::endl;	
}
void Warlock::learnSpell(ASpell *s)
{
	if(s)
	{
		this->spellBook[i++] = s;
	}
}
void Warlock::forgetSpell(std::string spell_name)
{
	int j = 0;
	while(j < 100)
	{
		if(spell_name == this->spellBook[j]->getName())
			this->spellBook[j] = 0;
	}
}
void Warlock::launchSpell(std::string spell_name, ATarget&other)
{
	int j = 0;
	while(j < 100)
	{
		if(spell_name == this->spellBook[j]->getName())
			this->spellBook[j]->launch(other);
	}

}
