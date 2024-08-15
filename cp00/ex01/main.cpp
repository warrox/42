#include <cstring>
#include <iostream>
#include <ostream>
namespace PhoneBooks {
	int test = 0;	
}; 

void add_contact(char *str)
{
	// init class PhoneBooks
	// pass ADD to get the rest of the sentence
	// 
}
int main(int argc, char **argv)
{
	char buffer[4096];
	std::cout<<"Welcome to Phone Book"<<std::endl;
	while(1)
	{
		std::cout<<"Menu : ADD[arg], SEARCH[arg], EXIT"<<std::endl;
		std::cin >> buffer;
		if(!strcmp(buffer, "ADD"))
		{
			add_contact(buffer);
		}
		if(!strcmp(buffer, "EXIT"))
			return(1);
	}
	return(0);
}
