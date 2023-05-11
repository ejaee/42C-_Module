#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    std::cout << "ScavTrap Default constructor called" << std::endl;

    this->m_name = "Default";
    this->m_hitPoints = 100;
    this->m_energyPoints = 50;
    this->m_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    std::cout << "\033[0;34mScavTrap [ " << name << " ] has been created\033[0m" << std::endl;

    this->m_hitPoints = 100;
    this->m_energyPoints = 50;
    this->m_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& scavTrap) {
    std::cout << "ScavTrap Copy constructor called" << std::endl;

    m_name = scavTrap.getName();
    m_hitPoints = scavTrap.getHitPoints();
    m_energyPoints = scavTrap.getEnergyPoints();
    m_attackDamage = scavTrap.getAttackDamage();
}

ScavTrap& ScavTrap::operator=(const ScavTrap& scavTrap) {
    std::cout << "ScavTrap Copy assignment operator called" << std::endl;

    if (this != &scavTrap) {
        m_name = scavTrap.getName();
        m_hitPoints = scavTrap.getHitPoints();
        m_energyPoints = scavTrap.getEnergyPoints();
        m_attackDamage = scavTrap.getAttackDamage();
    }
    return (*this);
}

ScavTrap::~ScavTrap(){
    std::cout << "\033[0;34mScavTrap [ " << m_name << " ] is destructed\033[0m" << std::endl;
}

void    ScavTrap::attack(const std::string& target) {
    if (m_energyPoints == 0) {
        std::cout << "[ " << m_name << " ] can no longer repair it" << std::endl;
        std::cout << "\033[0;31m[ Energy Points : " << m_energyPoints << " ]\033[0m" << std::endl;
        return ;
    }
    else if (m_hitPoints == 0) {
        std::cout << "[ " << m_name << " ] 's Hit Points is 0" << "\033[0;32m [ Energy Points : " << m_energyPoints << " ]\033[0m" << std::endl;
        return ;
    }
    std::cout   << "ScavTrap [ " << m_name 
                << " ] attack [ "<< target
                << " ], causing " << m_attackDamage 
                << " points of damage!" << std::endl;
    m_energyPoints--;
}

void    ScavTrap::guardGate() {
    if (m_energyPoints == 0) {
        std::cout << "[ " << m_name << " ] can no longer repair it" << std::endl;
        std::cout << "\033[0;31m[ Energy Points : " << m_energyPoints << " ]\033[0m" << std::endl;
        return ;
    }
    else if (m_hitPoints == 0) {
        std::cout << "[ " << m_name << " ] 's Hit Points is 0" << "\033[0;32m [ Energy Points : " << m_energyPoints << " ]\033[0m" << std::endl;
        return ;
    }
    std::cout   << "ScavTrap [ " << m_name << " ] has entered GateKeeper mode" << "\033[0;32m [ Energy Points : " << m_energyPoints << " ]\033[0m" << std::endl;
    m_energyPoints--;
}