#include "../includes/Base.hpp"

int main() {
    
	size_t value = 0;
	std::cout << "Press 1 to continue generate Base class or 2 to exit" << std::endl;		
	std::cin >> value;  
	while(1)
	{
		if(value == 1)
		{
			Base* obj = generate();
			identify(obj);
			identify(*obj);
			delete obj;
			value = 0;
			std::cout << "Press 1 to continue generate Base class or 2 to exit" << std::endl;
			std::cin >> value;
			if(value == 2)
				return(1);
		}
	}
    return 0;
}
