#pragma once
#include <cstddef>
#include <exception>
#include <string>
typedef  std::string string;
class Bureaucrat
{
	private:
		string _name;
		size_t _grade;
	public :
		// Bureaucrat();
		Bureaucrat(string name, size_t grade);
		~Bureaucrat();
		string getName(void)const;
		size_t getGrade(void)const;
		void increment(void);	
		void decrement(void);	
};

class GradeTooHighException:public std::exception{
public:
	const char *what() const throw();
};

class GradeTooLowException:public std::exception{
public:
	const char *what() const throw();
};
