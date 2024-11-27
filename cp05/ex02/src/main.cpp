#include <exception>
#include <iostream>
#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
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
		Bureaucrat w("Patoche", 1);
		std::cout << w;
		w.decrement();
	}
    catch(std::exception & e) {
		std::cout << e.what() << std::endl;
    }
	try
	{
		AForm f("Contract", 70, 150);
		Bureaucrat w("Bobby",70);
		w.signForm(&f);
		std::cout << f;
	}
	catch(std::exception & e)
	{
		std::cout <<e.what() << std::endl;	
	}


   return 0;
}
