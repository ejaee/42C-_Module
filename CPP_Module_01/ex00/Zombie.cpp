/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:32:14 by ejachoi           #+#    #+#             */
/*   Updated: 2023/05/04 15:32:15 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){};

Zombie::Zombie(std::string name){
    m_name = name;
}

Zombie::~Zombie(){
    std::cout << m_name << " is dead..." << std::endl;
}

void    Zombie::announce(){
    std::cout << m_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
