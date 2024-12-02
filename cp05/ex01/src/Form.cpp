
#include <cstddef>
#include <iostream>
#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

Form::Form(string name, size_t gradeS, size_t gradeE) : _name(name), _gradeSigned(gradeS), _gradeExec(gradeE)
{
	// std::cout <<"Form created" << std::endl;
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

Form::~Form()
{	
	// std::cout <<"Form destroyed" << std::endl;
}

size_t Form::getGradeSigned(void)const
{
	return(this->_gradeSigned);
}

size_t Form::getGradeExec(void)const
{
	return(this->_gradeExec);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return("Grade too high");
}
const char *Form::GradeTooLowException::what() const throw()
{
	return("Grade too low");
}

bool    Form::getIsSigned(void)const
{
	return(this->_signed);
}

std::ostream& operator<<(std::ostream& out, const Form& b) {
    out << BLUE << b.getName() << ", form grade " << b.getGradeSigned() << "." << RESET << std::endl;
    return out;
}

void Form::beSigned(Bureaucrat *employee)
{
	if(employee->getGrade() <= this->getGradeSigned())
	{
		this->_signed = true;	
	}
	else
	{
		throw (GradeTooLowException());
	}
}

string Form::getName(void)const
{
	return(this->_name);
}
