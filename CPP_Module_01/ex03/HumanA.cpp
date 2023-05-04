/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:32:37 by ejachoi           #+#    #+#             */
/*   Updated: 2023/05/04 15:32:38 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : m_name(name), m_weapon(weapon){}

HumanA::~HumanA() {
    std::cout << m_name << " is dead" << std::endl;
}

void    HumanA::attack() const {
    std::cout << m_name << " attacks with their " 
            << m_weapon.getType() << std::endl;
}
