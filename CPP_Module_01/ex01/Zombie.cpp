/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <choiejae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:32:24 by ejachoi           #+#    #+#             */
/*   Updated: 2023/05/12 11:36:55 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){}

Zombie::~Zombie(){
    std::cout << m_name << RED << ": is dead..." << RESET << std::endl;
}

void    Zombie::setName(std::string name){
    m_name = name;
}

void    Zombie::announce(){
    std::cout << m_name << YELLOW << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}
