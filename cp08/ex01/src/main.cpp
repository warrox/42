#include "../includes/span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib> // For rand()
#include <ctime>   // For time()

int main() {
    // Seed the random number generator for reproducible tests
    std::srand(std::time(0));

    try {
        // Create a Span instance with a maximum capacity of 5
        Span sp(5);

        std::cout << "Adding numbers to the Span:\n";
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        // Display results for shortest and longest spans
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        // Attempt to add another number to a full Span
        std::cout << "Trying to add another number...\n";
        sp.addNumber(42); // This should throw an exception
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        // Test with a larger Span
        Span largeSpan(10000);

        std::cout << "Filling a Span with 10,000 random numbers...\n";
        for (unsigned int i = 0; i < 10000; ++i) {
            largeSpan.addNumber(std::rand() % 100000); // Random numbers between 0 and 99,999
        }

        // Display results for shortest and longest spans
        std::cout << "Shortest span (large): " << largeSpan.shortestSpan() << std::endl;
        std::cout << "Longest span (large): " << largeSpan.longestSpan() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        // Test edge cases: empty Span
        Span emptySpan(5);
        std::cout << "Testing shortestSpan on an empty Span...\n";
        emptySpan.shortestSpan(); // Should throw an exception
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        // Test edge cases: Span with only one element
        Span singleSpan(5);
        singleSpan.addNumber(42);
        std::cout << "Testing shortestSpan on a Span with one number...\n";
        singleSpan.shortestSpan(); // Should throw an exception
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
