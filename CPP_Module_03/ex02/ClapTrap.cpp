#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
    std::cout << "ClapTrap Default constructor called" << std::endl;

    m_name = "Default";
    m_hitPoints = 10;
    m_energyPoints = 10;
    m_attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name) {
    std::cout << "\033[0;33mClapTrap [ " << name << " ] has been created\033[0m" << std::endl;

    m_name = name;
    m_hitPoints = 10;
    m_energyPoints = 10;
    m_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap) {
    std::cout << "ClapTrap Copy constructor called" << std::endl;

    m_name = clapTrap.getName();
    m_hitPoints = clapTrap.getHitPoints();
    m_energyPoints = clapTrap.getEnergyPoints();
    m_attackDamage = clapTrap.getAttackDamage();
}

ClapTrap& ClapTrap::operator=(const ClapTrap& clapTrap) {
    std::cout << "ClapTrap Copy assignment operator called" << std::endl;

    if (this != &clapTrap) {
        m_name = clapTrap.getName();
        m_hitPoints = clapTrap.getHitPoints();
        m_energyPoints = clapTrap.getEnergyPoints();
        m_attackDamage = clapTrap.getAttackDamage();
    }
    return (*this);
}

ClapTrap::~ClapTrap() {
    std::cout << "\033[0;33mClapTrap [ " << m_name << " ] is destructed\033[0m" << std::endl;
}

std::string ClapTrap::getName() const {
    return m_name;
}

unsigned int    ClapTrap::getHitPoints() const {
    return m_hitPoints;
}

unsigned int    ClapTrap::getEnergyPoints() const {
    return m_energyPoints;
}

unsigned int    ClapTrap::getAttackDamage() const {
    return m_attackDamage;
}

void    ClapTrap::attack(const std::string& target) {
    if (m_energyPoints == 0) {
        std::cout << "[ " << m_name << " ] can no longer repair it" << std::endl;
        std::cout << "\033[0;31m[ Energy Points : " << m_energyPoints << " ]\033[0m" << std::endl;
        return ;
    }
    else if (m_hitPoints == 0) {
        std::cout << "[ " << m_name << " ] 's Hit Points is 0" << "\033[0;32m [ Energy Points : " << m_energyPoints << " ]\033[0m" << std::endl;
        return ;
    }
    std::cout   << "ClapTrap [ " << m_name 
                << " ] attack [ "<< target
                << " ], causing " << m_attackDamage 
                << " points of damage!" << std::endl;
    m_energyPoints--;
}

void    ClapTrap::takeDamage(unsigned int amount) {
    if (m_hitPoints <= 0) {
        std::cout << "[ " << m_name << " ] \033[0;31m's already dead\033[0m"<< std::endl;
        return ;
    }
    std::cout << "\033[0;33m[ " << m_name << " ] is be damaged as much as " << amount << "\033[0m" << std::endl;
    
    if (m_hitPoints < amount) {
        std::cout << "[ " << m_name << " ]'s Hit Points is 0" << "\033[0;32m [ Energy Points : " << m_energyPoints << " ]\033[0m" << std::endl;
        m_hitPoints = 0;
    }
    else m_hitPoints -= amount;
}

void    ClapTrap::beRepaired(unsigned int amount) {
    if (m_energyPoints == 0) {
        std::cout << "[ " << m_name << " ] can no longer repair it " << "\033[0;31m[ Energy Points : " << m_energyPoints << " ]\033[0m" << std::endl;
        return ;
    }

    std::cout << "ClapTrap [ " << m_name << " ] be repaired \033[0;34m[ " << m_hitPoints;
    m_hitPoints += amount;
    std::cout << " -> " << m_hitPoints << " ]\033[0m" << std::endl;
    m_energyPoints--;
}
