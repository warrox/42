#include <cstddef>
#include <fstream>
#include <iostream>
#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
PresidentialPardonForm::PresidentialPardonForm(string target) : AForm("PresidentialPardonForm",25,5), _target(target) 
{
	// std::cout <<"PresidentialPardonForm created" << std::endl;
	this->_signed = false;
		if(this->_gradeSigned < 1 || this->_gradeExec < 1 )
		{
			throw (GradeTooHighException());
		}
		else if(this->_gradeSigned > 25 || this->_gradeExec > 5)
		{
			throw(GradeTooLowException());
		}
	
}

PresidentialPardonForm::~PresidentialPardonForm()
{	
	// std::cout <<"PresidentialPardonForm destroyed" << std::endl;
}
PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &rhs)
{
	(void)rhs;
	// if(this != &rhs)
	// {	
	// 	
	// }
	return(*this);
}
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &rhs) : AForm(rhs._name,rhs._gradeSigned,rhs._gradeExec) 
{
	if(this != &rhs)
		*this = rhs;
}
void PresidentialPardonForm::beSigned(Bureaucrat const *employee)
{
	if(employee->getGrade() <= this->getGradeSigned())
		this->_signed = true;
	else
		throw (GradeTooLowException());
}

void PresidentialPardonForm::execute(Bureaucrat const & executor)const {
	if (executor.getGrade() > this->getGradeExec()){
		throw GradeTooLowException();  	
	}
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;		
}






