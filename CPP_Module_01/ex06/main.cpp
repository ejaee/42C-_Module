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
