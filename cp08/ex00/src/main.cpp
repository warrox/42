#include "../includes/easyfind.hpp"
#include <vector>
#include <iostream>

int main() 
{
    std::vector<int> v1(20);
    for (int i = 0; i < 20; ++i) {
        v1[i] = i;
    }

    try {
        int to_find = 10;
        std::vector<int>::iterator result = easyfind(v1, to_find);
        std::cout << "Found number: " << *result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        int to_find = 21;
        std::vector<int>::iterator result = easyfind(v1, to_find);
        std::cout << "Found number: " << *result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
