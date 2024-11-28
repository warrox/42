#pragma once
#include <cstddef>
#include <exception>
#include <string>
#include <sstream>
#include "Colors.hpp"
#include "AForm.hpp"
typedef  std::string string;
class Bureaucrat;
class ShrubberyCreationForm : public AForm
{
	private :
		string _target;
	public :
		ShrubberyCreationForm(string target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm &operator=(ShrubberyCreationForm &);
		ShrubberyCreationForm(ShrubberyCreationForm &);	
		void beSigned(Bureaucrat const *employe);
		void execute(Bureaucrat const & executor) const;
				
};

std::ostream& operator<<(std::ostream& out, const ShrubberyCreationForm& b);
