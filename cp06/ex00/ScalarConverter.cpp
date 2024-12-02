#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

ScalarConverter::ScalarConverter(ScalarConverter &rhs)
{
	if(this != &rhs)
	{
		*this = rhs;
	}
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter &rhs)
{
	if(this != &rhs)
	{

	}
	return(*this);
}

void ScalarConverter::convert(std::string str)
{
	
}
