/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:32:42 by ejachoi           #+#    #+#             */
/*   Updated: 2023/05/04 15:32:43 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string const name) {
    m_name = name;
}

HumanB::~HumanB() {
    std::cout << m_name << " is dead" << std::endl;
}

void    HumanB::setWeapon(Weapon &weapon) {
    m_weapon = &weapon;
}

void    HumanB::attack() const {
    std::cout << m_name << " attacks with their " 
            << m_weapon->getType() << std::endl;

}
