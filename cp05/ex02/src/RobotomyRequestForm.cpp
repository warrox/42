#include <cstdlib>
#include <ctime>

#include <iostream>
#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
RobotomyRequestForm::RobotomyRequestForm(string target) : AForm("RobotomyRequestForm",72,45), _target(target) 
{
	// std::cout <<"RobotomyRequestForm created" << std::endl;
	this->_signed = false;
		if(this->_gradeSigned < 1 || this->_gradeExec < 1 )
		{
			throw (GradeTooHighException());
		}
		else if(this->_gradeSigned > 72 || this->_gradeExec > 45)
		{
			throw(GradeTooLowException());
		}
	
}

RobotomyRequestForm::~RobotomyRequestForm()
{	
	// std::cout <<"RobotomyRequestForm destroyed" << std::endl;
}
RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &rhs)
{
	if(this != &rhs)
	{	

	}
	return(*this);
}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &rhs) : AForm(rhs._name,rhs._gradeSigned,rhs._gradeExec) 
{
	if(this != &rhs)
	{
		*this = rhs;
	}	
}
void RobotomyRequestForm::beSigned(Bureaucrat const *employee)
{
	if(employee->getGrade() <= this->getGradeSigned())
		this->_signed = true;
	else
		throw (GradeTooLowException());
}


void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{	
	if (executor.getGrade() > this->getGradeExec()){
		throw GradeTooLowException();  	
	}

    std::cout << "BzzzbzZZZZZZZZZZZ" << std::endl;

    static bool seeded = false;
    if (!seeded)
    {
        std::srand(std::time(0));
        seeded = true;
    }

    if (std::rand() % 2)
    {
        std::cout << this->_target << " has been robotomized successfully!" << std::endl;
    }
    else
    {
        std::cout << "Robotomization of " << this->_target << " failed!" << std::endl;
    }
}

string RobotomyRequestForm::getTarget()const {
	return(this->_target);
}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& form) {
    os << "RobotomyRequestForm targeting " << form.getTarget();
    return os;
}
