#include "../includes/ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <cmath>

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }

void ScalarConverter::convert(const std::string& literal) {
    if (literal.empty()) {
        std::cerr << "Error: Empty string cannot be converted." << std::endl;
        return;
    }

    if (literal.length() == 1 && !std::isdigit(literal[0])) {
        char c = literal[0];
        printChar(c);
        printInt(static_cast<int>(c));
        printFloat(static_cast<float>(c));
        printDouble(static_cast<double>(c));
        return;
    }

    if (literal == "-inff" || literal == "+inff" || literal == "nanf") {
        printPseudoLiteral(literal);
        return;
    } else if (literal == "-inf" || literal == "+inf" || literal == "nan") {
        printPseudoLiteral(literal + "f");
        return;
    }

    char* end = NULL;

    double dValue = std::strtod(literal.c_str(), &end);
    if (*end != '\0' && *end != 'f') {
        std::cerr << "Error: Invalid literal." << std::endl;
        return;
    }

    bool isFloat = (*end == 'f');
    if (isFloat && end[1] != '\0') {
        std::cerr << "Error: Invalid float literal." << std::endl;
        return;
    }

    printChar(static_cast<char>(dValue));
    printInt(static_cast<int>(dValue));
    printFloat(static_cast<float>(dValue));
    printDouble(dValue);
}

void ScalarConverter::printChar(char value) {
    if (std::isprint(value)) {
        std::cout << "char: '" << value << "'" << std::endl;
    } else {
        std::cout << "char: Non displayable" << std::endl;
    }
}

void ScalarConverter::printInt(int value) {
    if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min()) {
        std::cout << "int: Overflow" << std::endl;
    } else {
        std::cout << "int: " << value << std::endl;
    }
}


void ScalarConverter::printFloat(float value) {
    std::cout << "float: " << std::fixed << std::setprecision(1) << value << "f" << std::endl;
}

void ScalarConverter::printDouble(double value) {
    std::cout << "double: " << value << std::endl;
}

void ScalarConverter::printPseudoLiteral(const std::string& pseudoLiteral) {
    if (pseudoLiteral == "-inff" || pseudoLiteral == "-inf") {
        std::cout << "char: Impossible" << std::endl;
        std::cout << "int: Impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    } else if (pseudoLiteral == "+inff" || pseudoLiteral == "+inf") {
        std::cout << "char: Impossible" << std::endl;
        std::cout << "int: Impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    } else if (pseudoLiteral == "nanf" || pseudoLiteral == "nan") {
        std::cout << "char: Impossible" << std::endl;
        std::cout << "int: Impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
}
