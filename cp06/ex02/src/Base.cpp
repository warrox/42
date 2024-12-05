#include "../includes/Base.hpp"

Base* generate(void) {
    std::srand(std::time(0));

    int randChoice = std::rand() % 3;

    if (randChoice == 0) {
        return new A();
    } else if (randChoice == 1) {
        return new B();
    } else {
        return new C();
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    }
}

void identify(Base& p)
{
    try {
       (void) dynamic_cast<A&>(p) ;
        std::cout << "it is A";
    }
    catch (std::exception &e)
    {
        try {
           (void) dynamic_cast<B&> (p);
             std::cout << "it is B";
        }
        catch (std::exception &e)
    {
        try {
            (void) dynamic_cast<C&> (p);
             std::cout << "it is C";
        }
        catch (std::exception &e)
        {

            std::cout << e.what() << std::endl;
        }
    }
}
}
