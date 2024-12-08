
#include <iostream>
#include "../includes/iter.hpp"

void increment(int& n) {
    n++;
}

void printString(std::string& str) {
    std::cout << str << " ";
}

void printInt(int& n) {
    std::cout << n << " ";
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArraySize = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Original int array: ";
    iter(intArray, intArraySize, printInt);
    std::cout << std::endl;

    std::cout << "Incrementing int array..." << std::endl;
    iter(intArray, intArraySize, increment);

    std::cout << "Modified int array: ";
    iter(intArray, intArraySize, printInt);
    std::cout << std::endl;

    std::string strArray[] = {"Hello", "world", "template", "iter"};
    size_t strArraySize = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "String array: ";
    iter(strArray, strArraySize, printString);
    std::cout << std::endl;

    return 0;
}

