#ifndef CONTACT_HPP
#define CONTACT_HPP


#include <iostream>

class Contact
{
public :
	Contact(void);
	~Contact(void);
	std::string f_name;
	std::string l_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
	bool is_created;
};

#endif
/*Un contact possède les champs suivants : first name (prénom), last name
(nom de famille), nickname (surnom), phone number (numéro de téléphone),
et darkest secret (son plus lourd secret). Les champs d’un contact enregistré ne
peuvent être vides.*/
