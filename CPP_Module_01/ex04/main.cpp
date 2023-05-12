/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <choiejae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:33:04 by ejachoi           #+#    #+#             */
/*   Updated: 2023/05/12 15:49:35 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileDto.hpp"

void    validateInput(int ac, char **av) {
    if (ac != 4)            throw std::string("Invalid input");
    
    std::string targetStr = av[2];
    if (targetStr.empty())  throw std::string("Invalid s1");
}

int main(int ac, char **av) {
    std::string buf;

    try {
        validateInput(ac, av);
        FileDto fileDto(av[1]);

        while (!std::getline(fileDto.getFin(), buf).eof() && fileDto.getFout().good()) {
            fileDto.replaceString(buf, av[2], av[3]);
        }     
        fileDto.replaceEndString(buf, av[2], av[3]);
        return 0;
    }   catch (const std::string message) {
        std::cerr << RED << "Error: " << message << RESET << std::endl;
        return 1;
    }
}
