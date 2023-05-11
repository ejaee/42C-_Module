#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"){
    std::cout << "DiamondTrap Default constructor called" << std::endl;

    m_name = "Default";
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name") {
    std::cout << "\033[0;34mDiamondTrap [ " << name << " ] has been created\033[0m" << std::endl;

    m_name = name;

}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondTrap) {
    std::cout << "DiamondTrap Copy constructor called" << std::endl;

    m_name = diamondTrap.getName();
    m_hitPoints = diamondTrap.getHitPoints();
    m_energyPoints = diamondTrap.getEnergyPoints();
    m_attackDamage = diamondTrap.getAttackDamage();
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& diamondTrap) {
    std::cout << "ScavTrap Copy assignment operator called" << std::endl;

    if (this != &diamondTrap) {
        m_name = diamondTrap.getName();
        m_hitPoints = diamondTrap.getHitPoints();
        m_energyPoints = diamondTrap.getEnergyPoints();
        m_attackDamage = diamondTrap.getAttackDamage();
    }
    return (*this);
}

DiamondTrap::~DiamondTrap(){
    std::cout << "\033[0;34mDiamondTrap [ " << m_name << " ] is destructed\033[0m" << std::endl;
}