#include "../includes/Array.hpp"
#include <iostream>
int main() {
    try {
        Array<int> a;
        std::cout << "Size of a: " << a.size() << std::endl;

        Array<int> b(5);
        std::cout << "Size of b: " << b.size() << std::endl;

        b[0] = 42;
        std::cout << "b[0]: " << b[0] << std::endl;

        try {
            b[10] = 24;
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

        Array<int> c(b);
        c[0] = 99;
        std::cout << "b[0]: " << b[0] << " (should be 42)" << std::endl;
        std::cout << "c[0]: " << c[0] << " (should be 99)" << std::endl;

    
        Array<int> d = b;
        d[0] = 77;
        std::cout << "b[0]: " << b[0] << " (should still be 42)" << std::endl;
        std::cout << "d[0]: " << d[0] << " (should be 77)" << std::endl;

    
        std::cout << "Size of d: " << d.size() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
