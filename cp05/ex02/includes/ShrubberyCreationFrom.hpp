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
	public :
		ShrubberyCreationForm(string name, size_t gradeS, size_t gradeE);
		~ShrubberyCreationForm();
		ShrubberyCreationForm &operator=(ShrubberyCreationForm &);
		ShrubberyCreationForm(ShrubberyCreationForm &);	
		size_t getGradeSigned(void)const;
		size_t getGradeExec(void)const;
		string getName(void)const;
		bool   getIsSigned(void)const;
		void increment(void);	
		void decrement(void);	
		void beSigned(Bureaucrat *employe);
		void signShrubberyCreationForm(Bureaucrat *employee);
		//Pure Method
		void execute(Bureaucrat const & executor)const;
		class GradeTooHighException:public std::exception{
		public:
			const char *what() const throw();
		};
		class GradeTooLowException:public std::exception{
		public:
			const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const ShrubberyCreationForm& b);
