#include "BitcoinExchange.hpp"

int main(int ac, char** av) {
    if (ac != 2) {
        std::cerr << RED << "Error: " << BitcoinExchange::OpenFileException().what() << std::endl << RESET;
        return 1;
    }

    BitcoinExchange bitcoinExchange(DATA_FILE);

    bitcoinExchange.run(av[1]);
}
