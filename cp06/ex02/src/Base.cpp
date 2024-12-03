#include "../includes/Base.hpp"

// Function to randomly generate an instance of A, B, or C
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

// Function to identify the type of the object pointed to by p (using pointer)
void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    }
}

// Function to identify the type of the object referenced by p (using reference)
void identify(Base& p) {
    // We can only use dynamic_cast for pointers in C++98, so we will use the pointer-based approach
    Base* pPtr = &p;
    identify(pPtr);
}
