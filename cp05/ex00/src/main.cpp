//// C++ program to demonstate property 2: Implicit type
/// conversion doesn't happen for primitive types.
// in exception handling.

#include <exception>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include "../includes/Bureaucrat.hpp"
int main()
{
	Bureaucrat w("Warren", 1);
	try {
		Bureaucrat n("Nathan",151); 
		// Bureaucrat x("pd", 1221); 
    }
    catch(std::exception & e) {
		std::cout << e.what() << std::endl;
    }
	// try
	// {
	//
	// }
   return 0;
}
