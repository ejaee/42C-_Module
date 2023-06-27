#include "easyfind.hpp"

#define MAX 10

void waitForTest(std::string nextStep) {
    std::cout << YELLOW << "\n[ Press any key to run the test ]\n" << std::endl << RESET;
    std::cin >> nextStep;
}

template <typename Container>
void testContainer(const std::string& containerName, Container& container) {
    std::cout << YELLOW << "---- Test the " << containerName << " container ----" << std::endl << RESET;
    try {
        typename Container::iterator iter;

        waitForTest("");
        iter = easyfind(container, 5);
        waitForTest("");
        iter = easyfind(container, 1000);
    } catch (const std::exception& e) {
        std::cout << RED << e.what() << std::endl << RESET;
    }
}

int main() {
    std::list<int> intList;
    std::deque<int> intDeque;
    std::vector<int> intVector;

    for (int idx = 0; idx < MAX; idx++) {
        intList.push_back(idx);
        intDeque.push_back(idx);
        intVector.push_back(idx);
    }

    testContainer("list", intList);
    testContainer("deque", intDeque);
    testContainer("vector", intVector);

    return 0;
}