#include "Zombie.hpp"

int main(){
    int N;
    std::string name;

    std::cout << "How many zombies would you create > ";
    std::cin >> N;
    std::cin.ignore();
    std::cout << "Please write zombie's name > ";
    std::getline(std::cin, name);
    if (std::cin.bad() || std::cin.fail() || std::cin.eof()){
        std::cout << "Error: invalid input" << std::endl;
        exit(1);
    }

    Zombie* zombies = zombieHorde(N, name);
    delete[] zombies;
    return 0;
}