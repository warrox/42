#include <cstdio>
#include <cstring>
#include <iostream>
#include <ostream>
#include "PhoneBook.hpp"


int main()
{
    PhoneBook pb;
    int i = 0;
    
    std::string command;
    while (true)
    {
        std::cout << "Menu: ADD, SEARCH, EXIT" << std::endl;
        std::cin >> command;
        std::cin.ignore();

        if (command == "ADD")
        {
            pb.add(i);
            i++;
        }
        else if (command == "SEARCH")
        {
            pb.search();
        }
        else if (command == "EXIT")
        {
            break;
        }
    }

    return 0;
}
