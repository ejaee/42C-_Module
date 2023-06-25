#include "Serializer.hpp"

int main() {
    Data ptr;
    ptr.name = "ejachoi";
    std::cout << &ptr << std::endl;

    uintptr_t intPtr;
    intPtr = Serializer::serializer(&ptr);
    std::cout << intPtr << std::endl;

    Data* data;
    data = Serializer::deserialize(intPtr);
    std::cout << data << std::endl;    

}