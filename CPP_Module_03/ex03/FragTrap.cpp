#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default") {
    std::cout << "FragTrap Default constructor called" << std::endl;

    this->m_hitPoints = 100;
    this->m_energyPoints = 100;
    this->m_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    std::cout << "\033[0;34mFragTrap [ " << name << " ] has been created\033[0m" << std::endl;

    this->m_hitPoints = 100;
    this->m_energyPoints = 100;
    this->m_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& fragTrap) {
    std::cout << "FragTrap Copy constructor called" << std::endl;

    m_name = fragTrap.getName();
    m_hitPoints = fragTrap.getHitPoints();
    m_energyPoints = fragTrap.getEnergyPoints();
    m_attackDamage = fragTrap.getAttackDamage();
}

FragTrap& FragTrap::operator=(const FragTrap& fragTrap) {
    std::cout << "FragTrap Copy assignment operator called" << std::endl;

    if (this != &fragTrap) {
        m_name = fragTrap.getName();
        m_hitPoints = fragTrap.getHitPoints();
        m_energyPoints = fragTrap.getEnergyPoints();
        m_attackDamage = fragTrap.getAttackDamage();
    }
    return (*this);
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap [ " << m_name << " ] is destructed" << std::endl;
}

void    FragTrap::highFivesGuys() {
    if (m_energyPoints == 0) {
        std::cout << "[ " << m_name << " ] can no longer repair it" << std::endl;
        std::cout << "\033[0;31m[ Energy Points : " << m_energyPoints << " ]\033[0m" << std::endl;
        return ;
    }
    else if (m_hitPoints == 0) {
        std::cout << "[ " << m_name << " ] 's Hit Points is 0" << "\033[0;32m [ Energy Points : " << m_energyPoints << " ]\033[0m" << std::endl;
        return ;
    }
    std::cout   << "FragTrap [ " << m_name << " ] high five!" << "\033[0;32m [ Energy Points : " << m_energyPoints << " ]\033[0m" << std::endl;
    m_energyPoints--;
}