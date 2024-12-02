#pragma once
#include <iostream>

class ScalarConverter
{
	private :

	public :
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(ScalarConverter &);
		ScalarConverter & operator=(ScalarConverter &);
		friend ScalarConverter operator""_char(char c);
		friend ScalarConverter operator""_int(long double val);
		friend ScalarConverter operator""_float(long double val);
		friend ScalarConverter operator""_double(long double val);
		static void convert(std::string str);
};
