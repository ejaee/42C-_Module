#include "FragTrap.hpp"

int main() {
    std::string nameA("marine");
    std::string nameB("zergling");
    std::string nameC("zealot");
    std::cout << "------------------------------------" << std::endl;

    FragTrap fragTrapA(nameA);
    FragTrap fragTrapB(nameB);
    std::cout << "------------------------------------" << std::endl;

    ClapTrap ClapTrapC(nameC);
    std::cout << "------------------------------------" << std::endl;
    
    fragTrapA.beRepaired(20);
    std::cout << "------------------------------------" << std::endl;

    fragTrapB.attack(nameA);
    fragTrapA.takeDamage(fragTrapB.getAttackDamage());
    fragTrapB.attack(nameA);
    fragTrapA.takeDamage(fragTrapB.getAttackDamage());
    fragTrapB.attack(nameA);
    fragTrapA.takeDamage(fragTrapB.getAttackDamage());
    fragTrapB.attack(nameA);
    fragTrapA.takeDamage(fragTrapB.getAttackDamage());
    fragTrapB.attack(nameA);
    fragTrapA.takeDamage(fragTrapB.getAttackDamage());
    fragTrapB.attack(nameA);
    fragTrapA.takeDamage(fragTrapB.getAttackDamage());
    fragTrapB.attack(nameA);
    fragTrapA.takeDamage(fragTrapB.getAttackDamage());
    std::cout << "------------------------------------" << std::endl;

    fragTrapA.highFivesGuys();
    fragTrapB.highFivesGuys();
    fragTrapB.highFivesGuys();
    std::cout << "------------------------------------" << std::endl;

}