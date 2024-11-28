/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:53:49 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/28 16:18:12 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include "ShrubberyCreationFrom.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class AForm;
typedef  std::string string;
class Intern
{
	private:
		AForm *_create_shrubberry(const string & target);
		AForm *_create_robotomy(const string & target);
		AForm *_create_presidential(const string & target);
		AForm *_create_form(const string & target, const int & index);
	public :
		Intern();
		~Intern();
		Intern(Intern &);
		Intern &operator=(Intern &);
		AForm *MakeForm(const string & form_name, const string & form_target);
};




#endif
