/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <choiejae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:32:28 by ejachoi           #+#    #+#             */
/*   Updated: 2023/05/12 11:32:41 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name){
    Zombie* zombies = new Zombie[N];
    char number = '1';

    for (int i = 0; i < N; i++){
        zombies[i].setName(name + "[ " + number++ + " ]");
        zombies[i].announce();
    }
    return zombies;
}
