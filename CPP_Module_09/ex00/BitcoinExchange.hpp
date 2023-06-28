#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# define RED    "\033[0;31m"
# define GREEN  "\033[1;32m"
# define YELLOW "\033[0;33m"
# define BLUE   "\033[0;34m"
# define RESET  "\033[0m"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

class BitcoinExchange {
    private:
        std::map<std::string, float> bitcoinData;

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& ref);
        BitcoinExchange& operator=(const BitcoinExchange& ref);
        ~BitcoinExchange();

        void    run(const char* path);
        void    validateInputFile(std::ifstream& db);
        std::map<std::string, float>    setBitcoinData(std::ifstream& db, std::string separator);
        const std::map<std::string, float>&    getData() const;

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

        class EmptyFileException : public std::exception {
            public:
                const char* what() const throw();
        };

        
        
};

#endif