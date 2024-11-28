#include <exception>
#include <iostream>
#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationFrom.hpp"
#include "../includes/PresidentialPardonForm.hpp"
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
		PresidentialPardonForm president("Brahim");
		Bureaucrat w("Bobby", 1);
		w.executeForm(president);
		// RobotomyRequestForm f("Contract");
		// RobotomyRequestForm AllesioLeBot("Pti'crack");
		// ShrubberyCreationForm tree("arbre");
		// w.signForm(&f);
		// AllesioLeBot.execute(w);
		// tree.execute(w);
		// president.execute(w);
		
		// std::cout << f;
	}
	catch(std::exception & e)
	{
		std::cout <<e.what() << std::endl;	
	}
	

   return 0;
}
