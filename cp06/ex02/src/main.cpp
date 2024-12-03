#include "../includes/Base.hpp"

int main() {
    // Create a random object using generate()
    Base* obj = generate();
    
    // Identify the type of object using the pointer-based identify
    identify(obj);

    // Identify the type of object using the reference-based identify
    identify(*obj);

    // Clean up
    delete obj;

    return 0;
}
