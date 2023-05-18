#include "DiamondTrap.hpp"

int main(void) {
    std::string nameA("marine");
    std::string nameB("zergling");
    std::string nameC("zealot");

    DiamondTrap diamondTrap1(nameA);
	std::cout << "------------------------------------" << std::endl;

	std::cout << "------------------------------------" << std::endl;
    std::cout << YELLOW << "\nPrint [ marine ] Status\n" << std::endl;

    std::cout << "Name: " << diamondTrap1.getName() << std::endl;
    std::cout << "Hit Points: " << diamondTrap1.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << diamondTrap1.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage: " << diamondTrap1.getAttackDamage() << RESET << std::endl;
	std::cout << "------------------------------------\n" << std::endl;

	std::cout << "------------------------------------" << std::endl;
    DiamondTrap diamondTrap2(nameB);
	std::cout << "------------------------------------" << std::endl;
    std::cout << std::endl;

	std::cout << "------------------------------------" << std::endl;
    ClapTrap clapTrap3(nameC);
	std::cout << "------------------------------------" << std::endl;
    std::cout << std::endl;

	std::cout << "------------------------------------" << std::endl;
    DiamondTrap diamondTrap4;
	std::cout << "------------------------------------" << std::endl;
    std::cout << std::endl;

	std::cout << "------------------------------------" << std::endl;
    diamondTrap1.attack(nameB);
    diamondTrap2.takeDamage(diamondTrap1.getAttackDamage());
    diamondTrap1.attack(nameB);
    diamondTrap2.takeDamage(diamondTrap1.getAttackDamage());
    diamondTrap1.attack(nameB);
    diamondTrap2.takeDamage(diamondTrap1.getAttackDamage());
	std::cout << "------------------------------------" << std::endl;
    std::cout << std::endl;

	std::cout << "------------------------------------" << std::endl;
    diamondTrap1.attack(nameC);
    clapTrap3.takeDamage(diamondTrap1.getAttackDamage());
    diamondTrap1.attack(nameC);
    clapTrap3.takeDamage(diamondTrap1.getAttackDamage());
    diamondTrap1.attack(nameC);
    clapTrap3.takeDamage(diamondTrap1.getAttackDamage());
	std::cout << "------------------------------------" << std::endl;
    std::cout << std::endl;
    
	std::cout << "------------------------------------" << std::endl;
    diamondTrap2.beRepaired(diamondTrap1.getAttackDamage() / 2);
    diamondTrap2.beRepaired(diamondTrap1.getAttackDamage() / 2);
	std::cout << "------------------------------------" << std::endl;
    std::cout << std::endl;

    std::cout << "------------------------------------" << std::endl;
    diamondTrap1.highFivesGuys();
    diamondTrap2.highFivesGuys();
    std::cout << "------------------------------------\n" << std::endl;
    
	return 0;
}