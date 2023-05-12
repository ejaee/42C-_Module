/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <choiejae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:32:52 by ejachoi           #+#    #+#             */
/*   Updated: 2023/05/12 14:39:26 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {
    m_type = "Fist";
}

Weapon::Weapon(std::string const type) {
    m_type = type;
}

Weapon::~Weapon() {
    std::cout << RED << m_type << " is destroy" << RESET << std::endl;
}

const std::string &Weapon::getType() const{
    return m_type;
}

void        Weapon::setType(std::string const type) {
    m_type = type;
}
