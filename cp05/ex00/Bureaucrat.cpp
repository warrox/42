#include "Bureaucrat.hpp"
#include <iostream>
// Bureaucrat::Bureaucrat()
// {
// 	std::cout <<"Bureaucrat created" << std::endl;
// }
Bureaucrat::Bureaucrat(string name, size_t grade) : _name(name), _grade(grade)
{
	std::cout <<"Bureaucrat created" << std::endl;
		if(this->_grade < 1 )
		{
			throw (GradeTooHighException());
		}
		else if(this->_grade > 150)
		{
			throw(GradeTooLowException());
		}
	
}

Bureaucrat::~Bureaucrat()
{	
	std::cout <<"Bureaucrat destroyed" << std::endl;
}
void Bureaucrat::increment(void)
{
	this->_grade++;	
}	
void Bureaucrat::decrement(void)
{
	this->_grade--;	
}
string Bureaucrat::getName(void)const
{
	return(this->_name);
}
size_t Bureaucrat::getGrade(void)const
{
	return(this->_grade);
}


const char *GradeTooHighException::what() const throw()
{
	return("Grade too high");
}
const char *GradeTooLowException::what() const throw()
{
	return("Grade too low");
}


