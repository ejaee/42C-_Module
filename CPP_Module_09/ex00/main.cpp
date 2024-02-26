#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << RED << "Error: " << BitcoinExchange::OpenFileException().what() << std::endl << RESET;
        return 1;
    }
    try {
        BitcoinExchange bitcoinExchange(DATA_FILE);

        bitcoinExchange.run(argv[1]);
    } catch(const std::exception& e) {
        std::cerr << RED << "CSV Error: " << e.what() << '\n' << RESET;
    }
}
