#pragma once
#include <cstddef>
#include <exception>
#include <string>
#include <sstream>
#include "Colors.hpp"
typedef  std::string string;

class Form
{
	private:
		string const _name;
		bool _signed;
		const size_t _gradeSigned;
		const size_t _gradeExec;
	public :
		Form();
		Form(string name, size_t gradeS, size_t gradeE, bool oisigned);
		~Form();
		size_t getGradeSigned(void)const;
		size_t getGradeExec(void)const;
		void increment(void);	
		void decrement(void);	
		class GradeTooHighException:public std::exception{
		public:
			const char *what() const throw();
		};

		class GradeTooLowException:public std::exception{
		public:
			const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const Form& b);
