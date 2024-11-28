/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:08:25 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/28 16:22:33 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"
Intern::Intern()
{
	// std::cout <<"Intern created" << std::endl;
}

Intern::~Intern()
{	
	// std::cout <<"Intern destroyed" << std::endl;
}
AForm *Intern::_create_shrubberry(const string & target){
	return new ShrubberyCreationForm(target);
}
AForm *Intern::_create_presidential(const string & target){
	return new PresidentialPardonForm(target);
}
AForm *Intern::_create_robotomy(const string & target){
	return new RobotomyRequestForm(target);
}
Intern &Intern::operator=(Intern &rhs)
{
	if(this != &rhs)
	{	
		
	}
	return(*this);
}
Intern::Intern(Intern &rhs) 
{
	if(this != &rhs)
	{
		*this = rhs;
	}	
}

AForm *Intern::_create_form(const string & target, const int & index){
	switch(index){
		case 0:
			return _create_robotomy(target);
		case 1:
			return _create_presidential(target);
		case 2:
			return _create_shrubberry(target);
		default:
			return 0;
	}
}

AForm *Intern::MakeForm(const string & form_name, const string & form_target){
	string tab[3] = {"robotomy request", "president pardon", "shrubberry creation"};
	for (int i = 0; i < 3; i++){
		if (tab[i] == form_name){
			return _create_form(form_target, i);
		}

	}
	return 0;
}
