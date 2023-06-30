#include "Array.hpp"

#define MAX 10

void    waitForTest(std::string nextStep) {
    std::cout << YELLOW << "\n[ Press any key to run the test ]\n" << std::endl << RESET;
    std::cin >> nextStep;
}

void CompareTwoStringValues(int* s1, Array<int> s2) {
    for (int idx = 0; idx < MAX; idx++) {
            if (s1[idx] != s2[idx])
                throw Array<int>::DiffValuesException();
        }
        std::cout << GREEN << "It worked fine." << std::endl << RESET;
}

int main() {
    srand(time(NULL));
    int* arr = new int[MAX];
    Array<int> userArr(MAX);
    
    std::cout << GREEN << "---- Generate a random number and store it in an array ----" << std::endl << RESET;
    waitForTest("");
    for (int idx = 0; idx < MAX; idx++) {
        const int randomValue = rand() % MAX + 1;
        std::cout << "[" << idx << "] saved number: " << randomValue << std::endl;
        arr[idx] = randomValue;
        userArr[idx] = randomValue;
    }
    
    Array<int> copyArr(userArr);
    Array<int> operatorArr = userArr;
    
    std::cout << GREEN << "---- Saving the string is complete! ----" << std::endl << RESET;

    try {
        std::cout << YELLOW << "---- Are the values stored in the two strings the same? ----" << std::endl << RESET;
        waitForTest("");
        CompareTwoStringValues(arr, userArr);
        waitForTest("");
        CompareTwoStringValues(arr, copyArr);
        waitForTest("");
        CompareTwoStringValues(arr, operatorArr);

    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << std::endl << RESET;
    }

    try {
        std::cout << YELLOW << "---- Does it output an error message if the index is out of range? ----" << std::endl << RESET;
        waitForTest("");
        userArr[-1] = 1;

    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << std::endl << RESET;
    }

    delete[] arr;
    return 0;

    // unsigned int x = -1;
    // int*a = new int[0];
    // int*b = NULL;
    // int*c = new int[x];

    // std::cout << a << std::endl;
    // std::cout << b << std::endl;
    // std::cout << c << std::endl;
    // std::cout << x << std::endl;
}