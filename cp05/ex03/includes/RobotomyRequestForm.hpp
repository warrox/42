#pragma once
#include <cstddef>
#include <exception>
#include <string>
#include <sstream>
#include "Colors.hpp"
#include "AForm.hpp"
typedef  std::string string;
class Bureaucrat;
class RobotomyRequestForm : public AForm
{
	private:
		string _target;
	public :
		RobotomyRequestForm(string target);
		~RobotomyRequestForm();
		RobotomyRequestForm &operator=(RobotomyRequestForm &);
		RobotomyRequestForm(RobotomyRequestForm &);	
		string getTarget(void)const;
		void beSigned(Bureaucrat const *employe);
		void execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream& out, const RobotomyRequestForm& b);
