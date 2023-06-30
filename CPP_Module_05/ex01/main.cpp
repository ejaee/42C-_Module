#include "Form.hpp"

void waitForTest(std::string nextStep) {
    std::cout << YELLOW << "\n[ Press any key to run the test ]\n" << std::endl << RESET;
    std::cin >> nextStep;
}

int main() {

    Bureaucrat tester1("CEO", 1);
    Bureaucrat tester2("Staff", 150);

    std::cout << YELLOW << "\n[ Test 1: CEO tries to sign the basic form ]\n" << RESET;
    waitForTest("");
    try {
        Form basic;
        
        tester1.signForm(basic);

    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET;
    }
    
    std::cout << YELLOW << "\n[ Test 2: Staff tries to sign the basic form ]\n" << RESET;
    waitForTest("");
    try {
        Form basic;
        
        tester2.signForm(basic);

    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET;
    }

    std::cout << YELLOW << "[ Test 3-1: over signGrade ]\n" << RESET;
    waitForTest("");
    try {
        Form over1("over1", 0, 70);
        std::cout << GREEN << over1 << RESET;

    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET;
    }

    std::cout << YELLOW << "[ Test 3-2: over execGrade ]\n" << RESET;
    waitForTest("");
    try {
        Form over2("over2", 70, 0);
        std::cout << GREEN << over2 << RESET;

    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET;
    }

    std::cout << YELLOW << "[ Test 4-1: under signGrade ]\n" << RESET;
    waitForTest("");
    try {
        Form under1("under1", 151, 70);
        std::cout << GREEN << under1 << RESET;

    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET;
    }

    std::cout << YELLOW << "[ Test 4-2: under execGrade ]\n" << RESET;
    waitForTest("");
    try {
        Form under2("under2", 70, 151);
        std::cout << GREEN << under2 << RESET;

    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET;
    }
}