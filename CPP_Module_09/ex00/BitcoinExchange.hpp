#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# define RED    "\033[0;31m"
# define GREEN  "\033[1;32m"
# define YELLOW "\033[0;33m"
# define BLUE   "\033[0;34m"
# define RESET  "\033[0m"

# define DATA_FILE "data.csv"
# define DATA_SEP ","
# define TARGET_DATA_SEP " | "

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <map>

class BitcoinExchange {
    private:
        std::map<std::string, double> bitcoinData;

    public:
        BitcoinExchange();
        BitcoinExchange(const char* csv_path);
        BitcoinExchange(const BitcoinExchange& ref);
        BitcoinExchange& operator=(const BitcoinExchange& ref);
        ~BitcoinExchange();

        void    run(const char* path);
        void    validateInputFile(std::ifstream& db);
        void    validateSeparator(std::istream& is, std::string separator);
        void    validateDate(int year, int month, int day);
        void    validatePrice(int price, bool flag);
        std::map<std::string, double>    setBitcoinData(std::ifstream& db, std::string separator);
        void    searchBitcoin(std::ifstream& db, std::string separator);

        const std::map<std::string, double>&    getData() const;

        class OpenFileException : public std::exception {
            public:
                const char* what() const throw();
        };
        class NotPosNumberException : public std::exception {
            public:
                const char* what() const throw();
        };
        class InvalidSeparatorException : public std::exception {
            public:
                const char* what() const throw();
        };
        class toLargePriceException : public std::exception {
            public:
                const char* what() const throw();
        };
        class EmptyFileException : public std::exception {
            public:
                const char* what() const throw();
        };
};

#endif
