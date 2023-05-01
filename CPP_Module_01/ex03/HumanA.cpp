#include "HumanA.hpp"

// HumanA::HumanA() {};

HumanA::HumanA(std::string name, Weapon& weapon) {
    // m_name = name;
    // m_weapon = weapon;

    m_name(name);
    m_weapon(weapon);
}

HumanA::~HumanA() {
    std::cout << m_name << " is dead" << std::cout;
};

void    HumanA::attack() {
    std::cout << m_name << " attack with " 
            << m_weapon.getType() << std::endl;
}
