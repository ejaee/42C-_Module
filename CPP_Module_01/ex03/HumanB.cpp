/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <choiejae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:32:42 by ejachoi           #+#    #+#             */
/*   Updated: 2023/05/12 14:43:11 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string const name) {
    m_name = name;
    m_weapon = new Weapon();
}

HumanB::~HumanB() {
    std::cout << RED << m_name << " is dead" << RESET << std::endl;
}

void    HumanB::setWeapon(Weapon &weapon) {
    m_weapon = &weapon;
}

void    HumanB::attack() const {
    if (m_weapon->getType() == "Fist") {
        std::cout   << m_name << " attacks with their " 
                    << m_weapon->getType() << std::endl;
    }
    else {
        std::cout   << YELLOW << m_name << RESET 
                << " attacks with their " 
                << YELLOW << m_weapon->getType() << RESET << std::endl;
    }
}
