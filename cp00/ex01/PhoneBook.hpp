
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
public:
    PhoneBook(void);
    ~PhoneBook(void);
    void add(int index);
    void search(void);
	void display_specific_contact(std::string command);
private:
    Contact _contacts[8];
    int _index;
};

#endif
