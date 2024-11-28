#include <cstddef>
#include <fstream>
#include <iostream>
#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationFrom.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(string target) : AForm("ShrubberyCreationForm",145,137), _target(target) 
{
	// std::cout <<"ShrubberyCreationForm created" << std::endl;
	this->_signed = false;
		if(this->_gradeSigned < 1 || this->_gradeExec < 1 )
		{
			throw (GradeTooHighException());
		}
		else if(this->_gradeSigned > 145 || this->_gradeExec > 137)
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
		*this = rhs;
}
void ShrubberyCreationForm::beSigned(Bureaucrat const *employee)
{
	if(employee->getGrade() <= this->getGradeSigned())
		this->_signed = true;
	else
		throw (GradeTooLowException());
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeExec()){
		throw GradeTooLowException();  	
	}
    std::string fileName = this->getName() + "_shrubbery";
    std::ofstream asciiTree(fileName.c_str());

    if (!asciiTree.is_open())
    {
        std::cerr << "Error: Failed to open or create file: " << fileName << std::endl;
        return;
    }

    asciiTree << "         _-_         " << std::endl;
    asciiTree << "      /~~   ~~\\      " << std::endl;
    asciiTree << "   /~~         ~~\\   " << std::endl;
    asciiTree << "  {               }  " << std::endl;
    asciiTree << "   \\  _-     -_  /   " << std::endl;
    asciiTree << "     ~  \\ //  ~      " << std::endl;
    asciiTree << "        | |           " << std::endl;
    asciiTree << "        |||           " << std::endl;
    asciiTree.close();
}





