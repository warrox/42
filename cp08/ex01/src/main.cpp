#include "../includes/span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}








































































// int main() {
//     std::srand(std::time(0));
//
//     try {
//         Span sp(5);
//
//         std::cout << "Adding numbers to the Span:\n";
//         sp.addNumber(6);
//         sp.addNumber(3);
//         sp.addNumber(17);
//         sp.addNumber(9);
//         sp.addNumber(11);
// 		sp.addNumber(1,100);
//         std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
//         std::cout << "Longest span: " << sp.longestSpan() << std::endl;
//
//         std::cout << "Trying to add another number..." << std::endl;
//         sp.addNumber(42);
//     } catch (const std::exception& e) {
//         std::cerr << "Exception: " << e.what() << std::endl;
//     }
//
//     try {
//         Span largeSpan(10000);
//
//         std::cout << "Filling a Span with 10,000 random numbers..." << std::endl;
//         for (unsigned int i = 0; i < 10000; ++i) {
//             largeSpan.addNumber(std::rand() % 100000);
//         }
//
//         std::cout << "Shortest span (large): " << largeSpan.shortestSpan() << std::endl;
//         std::cout << "Longest span (large): " << largeSpan.longestSpan() << std::endl;
//
//     } catch (const std::exception& e) {
//         std::cerr << "Exception: " << e.what() << std::endl;
//     }
//
//     try {
//         Span emptySpan(5);
//         std::cout << "Testing shortestSpan on an empty Span..." << std::endl;
//         emptySpan.shortestSpan();
//     } catch (const std::exception& e) {
//         std::cerr << "Exception: " << e.what() << std::endl;
//     }
//
//     try {
//         Span singleSpan(5);
//         singleSpan.addNumber(42);
//         std::cout << "Testing shortestSpan on a Span with one number..." << std::endl;
//         singleSpan.shortestSpan();
//     } catch (const std::exception& e) {
//         std::cerr << "Exception: " << e.what() << std::endl;
//     }
//
//     return 0;
// }
