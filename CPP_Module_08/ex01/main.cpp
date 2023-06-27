#include "Span.hpp"

#define SUCCESS "Success: Test passed"

void waitForTest(std::string nextStep) {
    std::cout << YELLOW << "\n[ Press any key to run the test ]\n" << std::endl << RESET;
    std::cin >> nextStep;
}

int main() {

    std::cout << YELLOW << "1. Subject test" << std::endl << RESET;
    waitForTest("");
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout << GREEN << SUCCESS << std::endl;

    std::cout << YELLOW << "2. Capacity test" << std::endl << RESET;
    waitForTest("");
    try {
        sp.addNumber(1);
        std::cout << GREEN << SUCCESS << std::endl;
    } catch (std::exception& e) {
        std::cerr << RED << e.what() << std::endl << RESET;
    }

    Span sp3 = Span(10000);
    std::cout << YELLOW << "3. Add many in one test" << std::endl << RESET;
    waitForTest("");
    try {
        sp3.addNumbersAsManyAs(10000);
        std::cout << GREEN << SUCCESS << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0; 
}