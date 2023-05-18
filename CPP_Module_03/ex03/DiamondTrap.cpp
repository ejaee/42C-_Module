#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"){
    std::cout << BLUE << "DiamondTrap Default constructor called" << RESET << std::endl;

    m_name = "Default";
    // m_energyPoints = ScavTrap::getEnergyPoints();
    m_energyPoints = 50;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name") {
    std::cout << BLUE << "DiamondTrap [ " << name << " ] has been created" << RESET << std::endl;

    m_name = name;
    // m_energyPoints = ScavTrap::getEnergyPoints();
    m_energyPoints = 50;
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
    std::cout << BLUE << "DiamondTrap [ " << m_name << " ] is destructed" << RESET << std::endl;
}

void DiamondTrap::whoAmI(void) {
  std::cout << "My name is " << m_name << "." << std::endl;
  std::cout << "My ClapTrap name is " << ClapTrap::getName() << "." << std::endl;
}
