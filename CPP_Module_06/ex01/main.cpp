#include "Serializer.hpp"

void waitForTest(std::string nextStep) {
    std::cout << YELLOW << "\n[ Press any key to run the test ]\n" << std::endl << RESET;
    std::cin >> nextStep;
}

int main() {

    std::cout << YELLOW << "Create a data class and output the address\n" << std::endl << RESET;
    waitForTest("");
    Data ptr;
    ptr.name = "ejachoi";
    std::cout << &ptr << std::endl;

    std::cout << YELLOW << "Serializing and outputting data class addresses\n" << std::endl << RESET;
    waitForTest("");
    uintptr_t intPtr;
    intPtr = Serializer::serializer(&ptr);
    std::cout << intPtr << std::endl;

    std::cout << YELLOW << "Restore the data class address\n" << std::endl << RESET;
    waitForTest("");
    Data* data;
    data = Serializer::deserialize(intPtr);
    std::cout << data << std::endl;    

}