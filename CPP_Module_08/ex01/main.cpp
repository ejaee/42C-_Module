#include "Span.hpp"
#include <cstdlib>

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
    
    std::cout << YELLOW << "2. Add many in one test" << std::endl << RESET;
    waitForTest("");
    try {
        int arr[] = {6, 3, 17, 9, 11};
        std::vector<int> vec(arr, arr + 5);
        Span sp2 = Span(5);

        sp2.addNumber<std::vector<int> >(vec.begin(), vec.end());
        
        std::cout << sp2.shortestSpan() << std::endl;
        std::cout << sp2.longestSpan() << std::endl;
        std::cout << GREEN << SUCCESS << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << YELLOW << "3. Capacity test" << std::endl << RESET;
    waitForTest("");
    try {
        sp.addNumber(1);
        std::cout << GREEN << SUCCESS << std::endl;
    } catch (std::exception& e) {
        std::cerr << RED << e.what() << std::endl << RESET;
    }

    Span sp4 = Span(10000);
    std::cout << YELLOW << "4. Add 10,000 in one test" << std::endl << RESET;
    waitForTest("");
    try {
        std::vector<int> vec2(10000);
        for (int idx = 0; idx < 10000; idx++)
            vec2[idx] = rand() % 1000 + 1;

        sp4.addNumber<std::vector<int> >(vec2.begin(), vec2.end());
        
        std::cout << sp4.shortestSpan() << std::endl;
        std::cout << sp4.longestSpan() << std::endl;
        std::cout << GREEN << SUCCESS << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0; 
}