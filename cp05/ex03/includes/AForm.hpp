#pragma once
#include <cstddef>
#include <exception>
#include <string>
#include <sstream>
#include "Colors.hpp"
typedef  std::string string;
class Bureaucrat;
class AForm
{
	protected:
		string const _name;
		bool _signed;
		const size_t _gradeSigned;
		const size_t _gradeExec;
	public :
		AForm();
		AForm(string name, size_t gradeS, size_t gradeE);
		virtual ~AForm();
		AForm &operator=(AForm &);
		AForm(AForm &);	
		size_t getGradeSigned(void)const;
		size_t getGradeExec(void)const;
		string getName(void)const;
		bool   getIsSigned(void)const;
		void increment(void);	
		void decrement(void);	
		void beSigned(Bureaucrat const *employe);
		void signAForm(Bureaucrat *employee);
		//Pure Method
		virtual void execute(Bureaucrat const & executor) const = 0;
		class GradeTooHighException:public std::exception{
		public:
			virtual const char *what() const throw();
		};
		class GradeTooLowException:public std::exception{
		public:
			virtual const char *what() const throw();
		};

};

std::ostream& operator<<(std::ostream& out, const AForm& b);
