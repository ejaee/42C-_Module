#include "Form.hpp"

int main() {

    std::cout << YELLOW << "\n[ Test 1: basic Constructor ]\n" << RESET;
    try {
        Form basic;
        std::cout << GREEN << basic << RESET;

    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET;
    }
    std::cout << YELLOW << "--------------------------------\n" << RESET << std::endl;

    std::cout << YELLOW << "[ Test 2: normal ]\n" << RESET;
    try {
        Form normal("normal", 1, 150);
        std::cout << GREEN << normal << RESET;

    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET;
    }
    std::cout << YELLOW << "--------------------------------\n" << RESET << std::endl;


    std::cout << YELLOW << "[ Test 3-1: over signGrade ]\n" << RESET;
    try {
        Form over1("over1", 0, 70);
        std::cout << GREEN << over1 << RESET;

    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET;
    }
    std::cout << YELLOW << "--------------------------------\n" << RESET << std::endl;


    std::cout << YELLOW << "[ Test 3-2: over execGrade ]\n" << RESET;
    try {
        Form over2("over2", 70, 0);
        std::cout << GREEN << over2 << RESET;

    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET;
    }
    std::cout << YELLOW << "--------------------------------\n" << RESET << std::endl;


    std::cout << YELLOW << "[ Test 4-1: under signGrade ]\n" << RESET;
    try {
        Form under1("under1", 151, 70);
        std::cout << GREEN << under1 << RESET;

    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET;
    }
    std::cout << YELLOW << "--------------------------------\n" << RESET << std::endl;


    std::cout << YELLOW << "[ Test 4-2: under execGrade ]\n" << RESET;
    try {
        Form under2("under2", 70, 151);
        std::cout << GREEN << under2 << RESET;

    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET;
    }
    std::cout << YELLOW << "--------------------------------\n" << RESET << std::endl;


    // std::cout << std::endl;

    // try {
    //     Bureaucrat under("Under_user", 151);
    //     std::cout << under;

    // } catch (const std::exception& e) {
    //     std::cerr << RED << e.what() << RESET;
    // }

}