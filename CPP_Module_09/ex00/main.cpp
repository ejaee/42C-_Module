#include "BitcoinExchange.hpp"

int main(int ac, char** av) {
    if (ac != 2) {
        std::cerr << "Error: " << BitcoinExchange::OpenFileException().what() << std::endl;
        return 1;
    }

    BitcoinExchange bitcoinExchange;

    bitcoinExchange.run(av[1]);
}


