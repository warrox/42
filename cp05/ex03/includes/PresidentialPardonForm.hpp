#pragma once
#include <cstddef>
#include <exception>
#include <string>
#include <sstream>
#include "Colors.hpp"
#include "AForm.hpp"
typedef  std::string string;
class Bureaucrat;
class PresidentialPardonForm : public AForm
{
	private :
		string _target;
	public :
		PresidentialPardonForm(string target);
		~PresidentialPardonForm();
		PresidentialPardonForm &operator=(PresidentialPardonForm &);
		PresidentialPardonForm(PresidentialPardonForm &);	
		void beSigned(Bureaucrat const *employe);
		void execute(Bureaucrat const & executor)const;
};

std::ostream& operator<<(std::ostream& out, const PresidentialPardonForm& b);
