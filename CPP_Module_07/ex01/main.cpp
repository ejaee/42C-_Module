#include "iter.hpp"

void waitForTest(std::string nextStep) {
    std::cout << YELLOW << "\n[ Press any key to run the test ]\n" << std::endl << RESET;
    std::cin >> nextStep;
}

int main() {

    std::cout << YELLOW << "test 1 for print intArr to run iter template\n" << std::endl << RESET;
    waitForTest("");
    int intArr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    iter(intArr, sizeof(intArr)/sizeof(*intArr), printArr);
    std::cout << std::endl;

    std::cout << YELLOW << "test 2 for print charArr to run iter template\n" << std::endl << RESET;
    waitForTest("");
    char charArr[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    ::iter(charArr, sizeof(charArr)/sizeof(*charArr), printArr);
    std::cout << std::endl;

    /**
     * 
    */
    std::cout << YELLOW << "test 3 for print charArr to run iter template\n" << std::endl << RESET;
    waitForTest("");
    std::string stringArr[10] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
    ::iter(stringArr, sizeof(stringArr)/sizeof(std::string), printArr);
    std::cout << std::endl;
}
