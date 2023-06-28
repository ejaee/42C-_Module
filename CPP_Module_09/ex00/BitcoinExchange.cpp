#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& ref) {
    bitcoinData = ref.getData();
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& ref) {
    if (this != &ref) 
        bitcoinData = ref.getData();
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

const std::map<std::string, float>&    BitcoinExchange::getData() const {
    return bitcoinData;
}

void    BitcoinExchange::validateInputFile(std::ifstream& db) {
    if (!db.is_open())
        throw BitcoinExchange::OpenFileException();
}


std::map<std::string, float> BitcoinExchange::setBitcoinData(std::ifstream& db, std::string separator) {
    std::map<std::string, float> database;
    std::string line;


    std::getline(db, line);

    while (std::getline(db, line)) {
        try {
            std::stringstream stream(line);
            size_t keySize;
            int year;
            int month;
            int day;
            double price;

            stream >> year;
            stream >> month;
            stream >> day;
            std::istream& is = stream;
            for (std::string::iterator iter = separator.begin(); iter != separator.end(); ++iter) {
                if (is.get() != *iter)
                    throw InvalidSeparatorException();
            }
            stream >> price;
            std::cout << "year : " << year << std::endl;
            std::cout << "month : " << month << std::endl;
            std::cout << "day : " << day << std::endl;
            std::cout << "price : " << price << std::endl;
        

            keySize = line.find(',');
            database[line.substr(0, keySize)] = price;
        } catch(const InvalidSeparatorException& e) {
            std::cerr << RED << "Error: " << e.what() << line << '\n' << RESET;
        } catch(...) {
            std::cerr << RED << "Error: " << e.what() << '\n' << RESET;
        }

    } 
    if (database.size() == 0)
	    throw EmptyFileException();

    return database;
}

void    BitcoinExchange::run(const char* path) {
    try {
        std::ifstream db(path);

        validateInputFile(db);
        bitcoinData = setBitcoinData(db, " | ");


    } catch (const std::exception& e) {
        std::cerr << RED << "Error: " << e.what() << '\n' << RESET;
        return ;
    }
}





const char * BitcoinExchange::OpenFileException::what() const throw()
{
	return "error message.";
}

const char * BitcoinExchange::NotPosNumberException::what() const throw()
{
	return "error message.";
}

const char * BitcoinExchange::InvalidSeparatorException::what() const throw()
{
	return "bad input => ";
}

const char * BitcoinExchange::EmptyFileException::what() const throw()
{
	return "error message.";
}
