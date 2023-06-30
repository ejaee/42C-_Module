#include "Bureaucrat.hpp"

void waitForTest(std::string nextStep) {
    std::cout << YELLOW << "\n[ Press any key to run the test ]\n" << std::endl << RESET;
    std::cin >> nextStep;
}

int main() {

    try {
        Bureaucrat basic;
        std::cout << basic;

    } catch (const std::exception& e) {
        std::cout << e.what();
    }

    waitForTest("");

    try {
        Bureaucrat use("User", 100);
        std::cout << use;

    } catch (const std::exception& e) {
        std::cout << e.what();
    }

    waitForTest("");

    try {
        Bureaucrat over("Over_user", 0);
        std::cout << over;

    } catch (const std::exception& e) {
        std::cout << RED << e.what() << RESET;
    }

    waitForTest("");

    try {
        Bureaucrat under("Under_user", 151);
        std::cout << under;

    } catch (const std::exception& e) {
        std::cout << RED << e.what() << RESET;
    }

    waitForTest("");

    try {
        Bureaucrat up("up_user", 1);
        std::cout << up;

    } catch (const std::exception& e) {
        std::cout << RED << e.what() << RESET;
    }

    waitForTest("");

    try {
        Bureaucrat down("down_user", 150);
        std::cout << down;

    } catch (const std::exception& e) {
        std::cout << RED << e.what() << RESET;
    }

}