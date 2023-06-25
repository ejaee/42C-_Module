#include "Serializer.hpp"

Serializer::Serializer() {

}

Serializer::Serializer(const Serializer& ref) {
    *this = ref;
}

Serializer& Serializer::operator=(const Serializer& ref) {
    if (this != &ref) {
        *this = ref;
    }
    return *this;
}

Serializer::~Serializer() {

}

uintptr_t Serializer::serializer(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}
