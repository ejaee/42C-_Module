#include "Form.hpp"

int main() {

    try {
        Form basic;
        std::cout << basic;

    } catch (const std::exception& e) {
        std::cerr << e.what();
    }

    std::cout << std::endl;

    try {
        Form over1("over1", 0, 70);
        Form over2("over2", 70, 0);
        std::cout << over1;
        std::cout << over2;

    } catch (const std::exception& e) {
        std::cerr << e.what();
    }

    std::cout << std::endl;

    try {
        Form under1("under1", 151, 70);
        Form under2("under2", 70, 151);

    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET;
    }

    // std::cout << std::endl;

    // try {
    //     Bureaucrat under("Under_user", 151);
    //     std::cout << under;

    // } catch (const std::exception& e) {
    //     std::cerr << RED << e.what() << RESET;
    // }

}