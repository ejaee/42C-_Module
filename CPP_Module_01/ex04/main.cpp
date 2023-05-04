/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:33:04 by ejachoi           #+#    #+#             */
/*   Updated: 2023/05/04 15:33:09 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileDto.hpp"

void    validateInput(int ac, char **av) {
    std::string str = av[2];

    if (ac != 4)        throw std::string("invalid input");
    if (str.empty())    throw std::string("Invalid s1");
}

int main(int ac, char **av) {
    std::string buf;

    try {
        validateInput(ac, av);
        FileDto fileDto(av[1]);

        while (std::getline(fileDto.getFin(), buf) && fileDto.getFout().good()) {
            fileDto.replaceString(buf, av[2], av[3]);
        }     
        return 0;
    }   catch (const std::string message) {
        std::cerr << "Error: " << message << std::endl;
        return 1;
    }
}
