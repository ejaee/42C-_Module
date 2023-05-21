#include "Animal.hpp"

/* ================= Orthodox Canonical Class Form ================= */

Animal::Animal() : m_type("Animal") {
    std::cout << "Default constructed" << std::endl;   
}

Animal::Animal(const Animal& animal) : m_type(animal.getType()) {
    std::cout << "Copy constructed" << std::endl;   
}

Animal& Animal::operator=(const Animal& animal) {
    if (this != &animal)
        m_type = animal.getType();
    std::cout << "Assigned" << std::endl;
    return *this;
}

Animal::~Animal() {
    std::cout << "Destructed" << std::endl;   
}

/* ================================================================= */

std::string    Animal::getType() const {
    return m_type;
}

std::ostream&   operator<<(std::ostream& o, const Animal& animal) {
    return o << animal.getType();
}
