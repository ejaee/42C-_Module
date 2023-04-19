#include "Zombie.hpp"

int main(){
    int N;
    std::string name;

    std::cout << "How many create Zombies >"
    std::cin >> N;
    std::cin.ignore();
    std::cout << "Input Zombie name >"
    std::getline(std::cin, name);
    if (cin.bad() || cin.fail() || cin.eof()){
        std::cout << "Error: cin" << std::endl;
        exit(1);
    }

    Zombie* zombie = new zombieHorde(N, name);
    for (int i = 0; i < N; i++){

    }

}