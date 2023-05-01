#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::Weapon(std::string type) {
    m_type = type;
}

Weapon::~Weapon() {
    std::cout << m_type << " is destroy" << std::cout;
}

std::string &Weapon::getType() {
    return m_type;
}

void        Weapon::setType(std::string type) {
    m_type = type;
}

