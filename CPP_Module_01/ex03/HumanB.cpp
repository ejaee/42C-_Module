#include "HumanB.hpp"

HumanB::HumanB(std::string const name) {
    m_name = name;
}

HumanB::~HumanB() {
    std::cout << m_name << " is dead" << std::endl;
}

void    HumanB::setWeapon(Weapon &weapon) {
    m_weapon = &weapon;
}

void    HumanB::attack() const {
    std::cout << m_name << " attacks with their " 
            << m_weapon->getType() << std::endl;

}