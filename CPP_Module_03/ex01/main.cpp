#include "ScavTrap.hpp"

int main() {
    std::string nameA("marine");
    std::string nameB("zergling");
    std::string nameC("zealot");
    std::cout << "------------------------------------" << std::endl;

    ClapTrap *scavPTR_A = new ScavTrap(nameA);

    std::cout << "------------------------------------" << std::endl;

    ScavTrap scavTrapB(nameB);

    std::cout << "------------------------------------" << std::endl;

    ClapTrap ClapTrapC(nameC);
    std::cout << "------------------------------------\n" << std::endl;
    
    std::cout << "------------------------------------" << std::endl;
    scavPTR_A->beRepaired(20);
    std::cout << "------------------------------------" << std::endl;

    scavTrapB.attack(nameA);
    scavPTR_A->takeDamage(scavTrapB.getAttackDamage());
    scavTrapB.attack(nameA);
    scavPTR_A->takeDamage(scavTrapB.getAttackDamage());
    scavTrapB.attack(nameA);
    scavPTR_A->takeDamage(scavTrapB.getAttackDamage());
    scavTrapB.attack(nameA);
    scavPTR_A->takeDamage(scavTrapB.getAttackDamage());
    scavTrapB.attack(nameA);
    scavPTR_A->takeDamage(scavTrapB.getAttackDamage());
    scavTrapB.attack(nameA);
    scavPTR_A->takeDamage(scavTrapB.getAttackDamage());
    scavTrapB.attack(nameA);
    scavPTR_A->takeDamage(scavTrapB.getAttackDamage());
    std::cout << "------------------------------------" << std::endl;

    // scavPTR_A->guardGate();
    scavTrapB.guardGate();
    scavTrapB.guardGate();
    std::cout << "------------------------------------\n" << std::endl;

    delete scavPTR_A;

}