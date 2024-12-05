

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
private:
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter&);
    ScalarConverter& operator=(const ScalarConverter&);

public:
    static void convert(const std::string& literal);

private:
    static void printChar(double value);
    static void printInt(double value);
    static void printFloat(float value);
    static void printDouble(double value);
    static void printPseudoLiteral(const std::string& pseudoLiteral);
};

#endif
