#include "AAnimal.hpp"

/* ================= Orthodox Canonical Class Form ================= */

AAnimal::AAnimal() : m_type("AAnimal") {
    std::cout << "Default constructed" << std::endl;   
}

AAnimal::AAnimal(const AAnimal& animal) : m_type(animal.getType()) {
    std::cout << "Copy constructed" << std::endl;   
}

AAnimal& AAnimal::operator=(const AAnimal& animal) {
    if (this != &animal)
        m_type = animal.getType();
    std::cout << "Assigned" << std::endl;
    return *this;
}

AAnimal::~AAnimal() {
    std::cout << "Destructed" << std::endl;   
}

/* ================================================================= */

std::string    AAnimal::getType() const {
    return m_type;
}

std::ostream&   operator<<(std::ostream& o, const AAnimal& animal) {
    return o << animal.getType();
}
