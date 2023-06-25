#include "iter.hpp"

int main() {
    std::string nextStep;

    /**
     * test 1 for print intArr to run iter template
    */
    std::cout << YELLOW << "\n[ Press any key to run the test 1 ]\n" << std::endl << RESET;
    std::cin >> nextStep;

    int intArr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ::iter(intArr, sizeof(intArr)/sizeof(*intArr), printArr);
    std::cout << std::endl;

    /**
     * test 2 for print charArr to run iter template
    */
    std::cout << YELLOW << "\n[ Press any key to run the test 2 ]\n" << std::endl << RESET;
    std::cin >> nextStep;

    char charArr[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    ::iter(charArr, sizeof(charArr)/sizeof(*charArr), printArr);
    std::cout << std::endl;

    /**
     * test 3 for print charArr to run iter template
    */
    std::cout << YELLOW << "\n[ Press any key to run the test 3 ]\n" << std::endl << RESET;
    std::cin >> nextStep;

    std::string stringArr[10] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
    ::iter(stringArr, sizeof(stringArr)/sizeof(std::string), printArr);
    std::cout << std::endl;
}
