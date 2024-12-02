#include <iostream>
#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"
Bureaucrat::Bureaucrat()
{
	// std::cout <<"Bureaucrat created" << std::endl;
}

Bureaucrat::Bureaucrat(string name, size_t grade) : _name(name), _grade(grade)
{
	// std::cout <<"Bureaucrat created" << std::endl;
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
	// std::cout <<"Bureaucrat destroyed" << std::endl;
}

void Bureaucrat::increment(void)
{
	this->_grade++;	
	if(this->_grade > 150)
		throw(GradeTooLowException());
}	
void Bureaucrat::decrement(void)
{
	this->_grade--;	
	if(this->_grade < 1)
		throw(GradeTooHighException());
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

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b) {
    out << BLUE << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << RESET << std::endl;
    return out;
}

void Bureaucrat::signForm(Form *form)
{
	try
	{
		form->beSigned(this);
		std::cout << MAGENTA <<  this->getName() << " signed "<< form->getName() << RESET << std::endl;
	}
	catch(GradeTooLowException())
	{
		std::cout << RED << this->getName() << " is only grade " << this->getGrade() << " and need to be grade " << form->getGradeSigned() << " to sign the form." << RESET << std::endl;
	}
}
