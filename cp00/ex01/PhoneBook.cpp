
#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <ostream>
#include <strings.h>

bool is_digit_between0_8(const std::string& command){
	if(command.length()!= 1)
	{
		return(false);
	}
	if(!std::isdigit(command[0]))
		return(false);
	int value =command[0] -  '0';
	return(value >= 0 && value <= 8);
}

PhoneBook::PhoneBook(void) : _index(0) {
}

PhoneBook::~PhoneBook(void) {
}


void PhoneBook::add(int index) {
    index %= 7;

    do {
        std::cout << "Enter a first name: ";
        std::getline(std::cin, _contacts[index].f_name);
        if (_contacts[index].f_name.empty()) {
            std::cout << "First name cannot be empty. Please try again." << std::endl;
        }
    } while (_contacts[index].f_name.empty());

    do {
        std::cout << "Enter a last name: ";
        std::getline(std::cin, _contacts[index].l_name);
        if (_contacts[index].l_name.empty()) {
            std::cout << "Last name cannot be empty. Please try again." << std::endl;
        }
    } while (_contacts[index].l_name.empty());

    do {
        std::cout << "Enter a nickname: ";
        std::getline(std::cin, _contacts[index].nickname);
        if (_contacts[index].nickname.empty()) {
            std::cout << "Nickname cannot be empty. Please try again." << std::endl;
        }
    } while (_contacts[index].nickname.empty());

    do {
        std::cout << "Enter a phone number: ";
        std::getline(std::cin, _contacts[index].phone_number);
        if (_contacts[index].phone_number.empty()) {
            std::cout << "Phone number cannot be empty. Please try again." << std::endl;
        }
    } while (_contacts[index].phone_number.empty());

    do {
        std::cout << "Enter a darkest secret: ";
        std::getline(std::cin, _contacts[index].darkest_secret);
        if (_contacts[index].darkest_secret.empty()) {
            std::cout << "Darkest secret cannot be empty. Please try again." << std::endl;
        }
    } while (_contacts[index].darkest_secret.empty());

    _contacts[index].is_created = true;

    _index = (_index + 1) % 7;
}

void PhoneBook::display_specific_contact(std::string command)
{
	int index = command[0] - '0';
	index = index - 1;
	if(_contacts[index].is_created)
	{
		std::cout << "Accesing contact [";std::cout << index + 1 << "]" << std::endl;
		std::cout << std::setw(10) << "First name : "<<_contacts[index].f_name.substr(0, 10) << std::endl;
		std::cout << std::setw(10) << "Last name : " << _contacts[index].l_name.substr(0, 10) << std::endl;
		std::cout << std::setw(10) << "Nickname : "<< _contacts[index].nickname.substr(0, 10) << std::endl;
	}
	else
	{
		std::cout << "no correspondant index found" << std::endl;
	}

}

void PhoneBook::search(void) { 
    std::string command;
	std::cout << " ___________________________________________ " << std::endl;
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;

    for (int i = 0; i < 8; ++i) {
        if (!_contacts[i].f_name.empty()) {
            std::cout << "|";
            std::cout << std::setw(10) << i + 1 << "|";

            std::string firstName = _contacts[i].f_name;
            if (firstName.length() > 10) {
                firstName = firstName.substr(0, 9) + ".";
            }
            std::cout << std::setw(10) << firstName << "|";

            std::string lastName = _contacts[i].l_name;
            if (lastName.length() > 10) {
                lastName = lastName.substr(0, 9) + ".";
            }
            std::cout << std::setw(10) << lastName << "|";

            std::string nickname = _contacts[i].nickname;
            if (nickname.length() > 10) {
                nickname = nickname.substr(0, 9) + ".";
            }
            std::cout << std::setw(10) << nickname << "|" << std::endl;

            std::cout << "|----------|----------|----------|----------|" << std::endl;
        }
    }

	std::cout << "Enter an index or press Enter to return to the menu: " << std::endl;
	getline(std::cin, command);

	if(command == "")
		return;

	if (is_digit_between0_8(command)) {
		display_specific_contact(command);
	} else {
		std::cout << "No corresponding index found." << std::endl;
	}
}
