#include "whatever.hpp"
#include <iostream>

int main() {
    std::string nextStep;

    std::cout << YELLOW << "\n[ Press any key to run the test 1 ]\n" << std::endl << RESET;
    std::cin >> nextStep;

    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

    std::cout << YELLOW << "\n[ Press any key to run the test 2 ]\n" << std::endl << RESET;
    std::cin >> nextStep;

    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

}