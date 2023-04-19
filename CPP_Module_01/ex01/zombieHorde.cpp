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