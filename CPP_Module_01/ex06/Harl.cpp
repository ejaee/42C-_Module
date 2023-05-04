/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:33:23 by ejachoi           #+#    #+#             */
/*   Updated: 2023/05/04 15:33:25 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {

    m_level[0] = "DEBUG";
    m_level[1] = "INFO";
    m_level[2] = "WARNING";
    m_level[3] = "ERROR";
    m_funcPointer[0] = &Harl::debug;
    m_funcPointer[1] = &Harl::info;
    m_funcPointer[2] = &Harl::warning;
    m_funcPointer[3] = &Harl::error;
}

Harl::~Harl() {}

void    Harl::debug(void) {
    std::cout << "[ DEBUG ]"<< std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. \nI really do!\n" << std::endl;
}

void    Harl::info(void) {
    std::cout << "[ INFO ]"<< std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. \nYou didn't put enough bacon in my burger! \nIf you did, I wouldn't be asking for more!\n" << std::endl;
}

void    Harl::warning(void) {
    std::cout << "[ WARNING ]"<< std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. \nI've been coming for years whereas you started working here since last month\n" << std::endl;
}

void    Harl::error(void) {
    std::cout << "[ ERROR ]"<< std::endl;
    std::cout << "This is unacceptable! \nI want to speak to the manager now.\n" << std::endl;
}

int    Harl::findIndex(const std::string level) {
    for (int i = 0; i < 4; i++) {
        if (!m_level[i].compare(level))
            return i;
    }
    return -1;
}

void    Harl::complain(const std::string inputLevel) {

    switch (findIndex(inputLevel))
    {
    case 0:
        (this->*m_funcPointer[0])();

    case 1:
        (this->*m_funcPointer[1])();

    case 2:
        (this->*m_funcPointer[2])();

    case 3:
        (this->*m_funcPointer[3])();
        break;
    
    default:
        throw std::string("[ Probably complaining about insignificant problems ]");
    }
}
