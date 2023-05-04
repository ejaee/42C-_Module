/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:33:29 by ejachoi           #+#    #+#             */
/*   Updated: 2023/05/04 15:33:31 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av) {
    
    Harl harl;

    try {
        if (ac != 2) {
            throw std::string("invalid argc\n");
        }
        harl.complain(av[1]);
    } catch (const std::string message) {
        std::cout << "Error: " << message << std::endl;
    }
}
