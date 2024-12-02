#pragma once
#include <cstddef>
#include <exception>
#include <string>
#include <sstream>
#include "Colors.hpp"
class Form;
typedef  std::string string;
class Bureaucrat
{
	private:
		string const _name;
		size_t _grade;
	public :
		Bureaucrat();
		Bureaucrat(string name, size_t grade);
		~Bureaucrat();
		string getName(void)const;
		size_t getGrade(void)const;
		void increment(void);	
		void decrement(void);	
		void signForm(Form *form);
};

class GradeTooHighException:public std::exception{
public:
	const char *what() const throw();
};

class GradeTooLowException:public std::exception{
public:
	const char *what() const throw();
};
std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);
