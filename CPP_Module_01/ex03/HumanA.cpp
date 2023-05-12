/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <choiejae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:32:37 by ejachoi           #+#    #+#             */
/*   Updated: 2023/05/12 14:43:16 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : m_name(name), m_weapon(weapon){}

HumanA::~HumanA() {
    std::cout << RED << m_name << " is dead" << RESET << std::endl;
}

void    HumanA::attack() const {
    std::cout   << YELLOW << m_name << RESET 
                << " attacks with their " 
                << YELLOW << m_weapon.getType() << RESET << std::endl;
}
