#include <cstddef>
#include <iostream>
#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationFrom.hpp"
ShrubberyCreationForm::ShrubberyCreationForm(string name, size_t gradeS, size_t gradeE) : AForm(name,gradeS,gradeE) 
{
	// std::cout <<"ShrubberyCreationForm created" << std::endl;
	this->_signed = false;
		if(this->_gradeSigned < 1 || this->_gradeExec < 1 )
		{
			throw (GradeTooHighException());
		}
		else if(this->_gradeSigned > 150 || this->_gradeExec > 150)
		{
			throw(GradeTooLowException());
		}
	
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{	
	// std::cout <<"ShrubberyCreationForm destroyed" << std::endl;
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &rhs)
{
	if(this != &rhs)
	{	
		
	}
	return(*this);
}
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &rhs) : AForm(rhs._name,rhs._gradeSigned,rhs._gradeExec) 
{
	if(this != &rhs)
	{
		*this = rhs;
	}	
}

// size_t ShrubberyCreationForm::getGradeSigned(void)const
// {
// 	return(this->_gradeSigned);
// }
// size_t ShrubberyCreationForm::getGradeExec(void)const
// {
// 	return(this->_gradeExec);
// }


// const char *ShrubberyCreationForm::GradeTooHighException::what() const throw()
// {
// 	return("Grade too high");
// }
// const char *ShrubberyCreationForm::GradeTooLowException::what() const throw()
// {
// 	return("Grade too low");
// }






