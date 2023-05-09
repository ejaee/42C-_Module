#include "ClapTrap.hpp"

int main() {
    std::string nameA("marine");
    std::string nameB("zergling");


    std::cout << "------------------------------------" << std::endl;
    ClapTrap clapTrapA(nameA);
    ClapTrap clapTrapB(nameB);
    std::cout << "------------------------------------" << std::endl;
    
    clapTrapA.beRepaired(10);
    std::cout << "------------------------------------" << std::endl;

    clapTrapB.attack(nameA);
    clapTrapB.attack(nameA);
    clapTrapA.takeDamage(10);
    std::cout << "------------------------------------" << std::endl;

    clapTrapB.beRepaired(10);
    clapTrapB.beRepaired(10);
    clapTrapB.beRepaired(10);
    clapTrapB.beRepaired(10);
    clapTrapB.beRepaired(10);
    clapTrapB.beRepaired(10);
    clapTrapB.beRepaired(10);
    clapTrapB.beRepaired(10);
    clapTrapB.beRepaired(10);
    std::cout << "------------------------------------" << std::endl;

}