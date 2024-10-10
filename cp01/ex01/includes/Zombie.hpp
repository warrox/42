
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP


#include <iostream>
#include <string>

// class Contact {
// private:
//     std::string f_name;
//     std::string l_name;
//     std::string nickname;
//     std::string phone_number;
//     std::string darkest_secret;
//     bool is_created;
//
// public:
//     Contact() : is_created(false) {}
//
//     // Getters
//     std::string getFirstName() const { return f_name; }
//     std::string getLastName() const { return l_name; }
//     std::string getNickname() const { return nickname; }
//     std::string getPhoneNumber() const { return phone_number; }
//     std::string getDarkestSecret() const { return darkest_secret; }
//     bool isCreated() const { return is_created; }
//
//     // Setters
//     void setFirstName(const std::string& fname) { f_name = fname; }
//     void setLastName(const std::string& lname) { l_name = lname; }
//     void setNickname(const std::string& nname) { nickname = nname; }
//     void setPhoneNumber(const std::string& phone) { phone_number = phone; }
//     void setDarkestSecret(const std::string& secret) { darkest_secret = secret; }
//     void setIsCreated(bool created) { is_created = created; }
// };

class Zombie
{
	private:
		std::string name;
};

Zombie* zombieHorde( int N, std::string name );
#endif
