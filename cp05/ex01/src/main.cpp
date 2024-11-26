#include <exception>
#include <iostream>
#include "../includes/Bureaucrat.hpp"
#include "../includes/Colors.hpp"
int main()
{
	try {
		// w.decrement();
		Bureaucrat n("Nathan",151); 
		std::cout << n << std::endl;
		// Bureaucrat x("pd", 1221); 
    }
    catch(std::exception & e) {
		std::cout << e.what() << std::endl;
    }
	try
	{
		Bureaucrat w("Warren", 1);
		std::cout << w;
		w.decrement();
	}
    catch(std::exception & e) {
		std::cout << e.what() << std::endl;
    }

   return 0;
}
