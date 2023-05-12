/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <choiejae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:32:21 by ejachoi           #+#    #+#             */
/*   Updated: 2023/05/12 14:16:09 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(){
    int N;
    std::string name;

    std::cout << GREEN << "How many zombies would you create > " << RESET;
    std::cin >> N;
    std::cin.ignore();
    if (N > 0) {
        std::cout << GREEN << "Please write zombie's name > " << RESET;
        std::getline(std::cin, name);
    }
    if (N < 0 || std::cin.bad() || std::cin.fail() || std::cin.eof()){
        std::cout << RED << "\nError: invalid input" << RESET << std::endl;
        exit(1);
    }
    
    Zombie* zombies = zombieHorde(N, name);
    delete[] zombies;
    return 0;
}
