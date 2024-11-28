
#include <cstddef>
#include <iostream>
#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"

AForm::AForm() : _name("default"), _gradeSigned(100), _gradeExec(150){}

AForm::AForm(string name, size_t gradeS, size_t gradeE) : _name(name), _gradeSigned(gradeS), _gradeExec(gradeE)
{
	// std::cout <<"AForm created" << std::endl;
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

AForm::~AForm()
{	
	// std::cout <<"AForm destroyed" << std::endl;
}
AForm &AForm::operator=(AForm &rhs)
{
	if(this != &rhs)
	{	
		
	}
	return(*this);
}
AForm::AForm(AForm &rhs) : _name(rhs.getName()), _gradeSigned(rhs.getGradeSigned()), _gradeExec(rhs.getGradeExec()) 
{
	if(this != &rhs)
	{
		*this = rhs;
	}	
}
size_t AForm::getGradeSigned(void)const
{
	return(this->_gradeSigned);
}
size_t AForm::getGradeExec(void)const
{
	return(this->_gradeExec);
}


const char *AForm::GradeTooHighException::what() const throw()
{
	return("Grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return("Grade too low");
}

bool    AForm::getIsSigned(void)const
{
	return(this->_signed);
}
std::ostream& operator<<(std::ostream& out, const AForm& b) {
    out << BLUE << b.getName() << ", form grade " << b.getGradeSigned() << "." << RESET << std::endl;
    return out;
}

void AForm::beSigned(Bureaucrat const *employee)
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


string AForm::getName(void)const
{
	return(this->_name);
}

// void AForm::execute(Bureaucrat const & executor)
// {
// 	if(this->getGradeSigned() && executor.getGrade() <= this->getGradeExec())
// 	{
// 		this->beSigned(&executor);
// 		
// 	}
// }
