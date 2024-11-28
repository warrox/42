#include <exception>
#include <iostream>
#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationFrom.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Intern.hpp"
#include "../includes/Colors.hpp"


int main(void){
	Intern a;
	AForm* form;
	Bureaucrat b("Tom", 1);

	form = a.MakeForm("robotomy request", "Blender");
	form->execute(b);
}
