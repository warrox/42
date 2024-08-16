#include <cstdio>
#include <cstring>
#include <iostream>
#include <ostream>
#include "PhoneBook.hpp"

void search_data(PhoneBook& pb)
{
	int i = 0;
	while(i<= // longeur de  ton phonebook)
	{
		
		std::cout << "index : ["<<i <<"]"<< std::endl; 
		std::cout << "first name : []"<< std::endl; 
		std::cout << "last name : []"<< std::endl; 
		std::cout << "Nick name : []"<< std::endl; 	
	}
}

void get_data(PhoneBook& pb, int i)
{
	if(i == 7)
	{
		pb.array_contact[0][0]= pb.cont.f_name;
		pb.array_contact[0][1] = pb.cont.l_name;
		pb.array_contact[0][2] = pb.nickname;
		pb.array_contact[0][3] = pb.phonenumber;
		pb.array_contact[0][4] = pb.darkestsecret;
	}
	else
	{
		pb.array_contact[i][0]= pb.cont.f_name;
		pb.array_contact[i][1] = pb.cont.l_name;
		pb.array_contact[i][2] = pb.nickname;
		pb.array_contact[i][3] = pb.phonenumber;
		pb.array_contact[i][4] = pb.darkestsecret;
	}
}
void add_contact(std::string buff, PhoneBook& pb)
{
	std::cout << "Enter a first name " <<std::endl;
	std::getline(std::cin, pb.cont.f_name);
	
	std::cout << "last name ?" <<std::endl;
	std::getline(std::cin, pb.cont.l_name);
	
	std::cout << " Nickname ?" <<std::endl;
	std::getline(std::cin, pb.cont.nickname);

	std::cout << "Phone number ?" <<std::endl;
	std::getline(std::cin, pb.cont.phone_number);
	
	std::cout << "Darkest Secret ? 😈" <<std::endl;	
	std::getline(std::cin, pb.cont.darkest_secret);
}
int main(int argc, char **argv)
{
	int i = 0;
	std::string buff;
	PhoneBook pb;	
	std::cout<<"Welcome to Phone Book"<<std::endl;
	while(1)
	{
		std::cout<<"Menu : ADD[arg], SEARCH[arg], EXIT"<<std::endl;
		std::cin >> buff;
		if(!buff.compare(0,3,"ADD")) // replace by string compare
		{
			add_contact(buff, pb);
			i++;
			get_data(pb, i);
		}
		if(!buff.compare(0,6,"SEARCH")) // replace by string compare
		{				
			search_data(pb, i);
		}

		if(!buff.compare(0,4, "EXIT"))
			return(1);
	}
	return(0);
}
