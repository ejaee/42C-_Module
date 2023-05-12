/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <choiejae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:32:47 by ejachoi           #+#    #+#             */
/*   Updated: 2023/05/12 14:42:58 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main() {

    std::cout << GREEN << "\n>>> TEST 1 <<<\n" << RESET << std::endl;
    {
        Weapon club = Weapon("Sword");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("Bow"); 
        bob.attack();
    }

    std::cout << GREEN << "\n>>> TEST 2 <<<\n" << RESET << std::endl;
    {
        HumanB Sam("Sam");
        Sam.attack();
    }

    std::cout << GREEN << "\n>>> TEST 3 <<<\n" << RESET << std::endl;
    {
        Weapon club = Weapon("Sword");
        
        HumanB jim("Jim");
        jim.attack();
        jim.setWeapon(club);
        jim.attack();
        club.setType("Bow");
        jim.attack();

    }
    return 0;
}
