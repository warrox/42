

#include <iostream>
#include "../includes/ScalarConverter.hpp"

int main() {
    std::string input;
    std::cout << "Enter a value to convert: ";
    std::getline(std::cin, input); // Read user input (supports spaces, etc.)
    
    ScalarConverter::convert(input); // Pass user input to the converter

    return 0;
}
