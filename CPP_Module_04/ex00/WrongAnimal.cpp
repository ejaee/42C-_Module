#include "WrongAnimal.hpp"

/* ================= Orthodox Canonical Class Form ================= */

WrongAnimal::WrongAnimal() : m_type("WrongAnimal") {
    std::cout << "Default constructed" << std::endl;   
}

WrongAnimal::WrongAnimal(const WrongAnimal& wrongAnimal) : m_type(wrongAnimal.getType()) {
    std::cout << "Copy constructed" << std::endl;   
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& wrongAnimal) {
    if (this != &wrongAnimal)
        m_type = wrongAnimal.getType();
    std::cout << "Assigned" << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "Destructed" << std::endl;   
}

/* ================================================================= */

std::string    WrongAnimal::getType() const {
    return m_type;
}

void    WrongAnimal::makeSound() const {
    std::cout << "[ " << m_type << " ] " 
                << "Function is not yet implemented" << std::endl;
}

std::ostream&   operator<<(std::ostream& o, const WrongAnimal& wrongAnimal) {
    return o << wrongAnimal.getType();
}
