#include "ScavTrap.hpp"

int main() {
    std::string nameA("marine");
    std::string nameB("zergling");
    std::string nameC("zealot");
    std::cout << "------------------------------------" << std::endl;

    ScavTrap scavTrapA(nameA);
    ScavTrap scavTrapB(nameB);
    std::cout << "------------------------------------" << std::endl;

    ClapTrap ClapTrapC(nameC);
    std::cout << "------------------------------------" << std::endl;
    
    scavTrapA.beRepaired(20);
    std::cout << "------------------------------------" << std::endl;

    scavTrapB.attack(nameA);
    scavTrapA.takeDamage(scavTrapB.getAttackDamage());
    scavTrapB.attack(nameA);
    scavTrapA.takeDamage(scavTrapB.getAttackDamage());
    scavTrapB.attack(nameA);
    scavTrapA.takeDamage(scavTrapB.getAttackDamage());
    scavTrapB.attack(nameA);
    scavTrapA.takeDamage(scavTrapB.getAttackDamage());
    scavTrapB.attack(nameA);
    scavTrapA.takeDamage(scavTrapB.getAttackDamage());
    scavTrapB.attack(nameA);
    scavTrapA.takeDamage(scavTrapB.getAttackDamage());
    scavTrapB.attack(nameA);
    scavTrapA.takeDamage(scavTrapB.getAttackDamage());
    std::cout << "------------------------------------" << std::endl;

    scavTrapA.guardGate();
    scavTrapB.guardGate();
    scavTrapB.guardGate();
    std::cout << "------------------------------------" << std::endl;

}