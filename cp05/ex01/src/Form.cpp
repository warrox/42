
#include <cstddef>
#include <iostream>

#include "../includes/Form.hpp"
// Form::Form()
// {
// 	// std::cout <<"Form created" << std::endl;
// }
Form::Form(string name, size_t gradeS, size_t gradeE, bool oisigned) : _name(name), _gradeSigned(gradeS), _gradeExec(gradeE), _signed(oisigned)
{
	// std::cout <<"Form created" << std::endl;
		if(this->_gradeSigned < 1 || this->_gradeExec )
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
// void Form::increment(void)
// {
// 	this->_grade++;	
// 	if(this->_grade > 150)
// 		throw(GradeTooLowException());
// }	
// void Form::decrement(void)
// {
// 	this->_grade--;	
// 	if(this->_grade < 1)
// 		throw(GradeTooHighException());
// }
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

// std::ostream& operator<<(std::ostream& out, const Form& b) {
//     out << BLUE << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << RESET << std::endl;
//     return out;
// }
