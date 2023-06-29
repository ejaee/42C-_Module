#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const char* csv_path) {
    std::ifstream price_dataBase(csv_path);
    try {
        validateInputFile(price_dataBase);
        bitcoinData = setBitcoinData(price_dataBase, DATA_SEP);
    } catch(const std::exception& e) {
        std::cerr << RED << "CSV Error: " << e.what() << '\n' << RESET;
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& ref) {
    bitcoinData = ref.getData();
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& ref) {
    if (this != &ref) 
        bitcoinData = ref.getData();
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void    BitcoinExchange::run(const char* path) {
    try {
        std::ifstream db(path);

        validateInputFile(db);
        searchBitcoin(db, TARGET_DATA_SEP);
    } catch (const std::exception& e) {
        std::cerr << RED << "Error: " << e.what() << '\n' << RESET;
        return ;
    }
}

void    BitcoinExchange::validateInputFile(std::ifstream& db) {
    if (!db.is_open())
        throw BitcoinExchange::OpenFileException();
}

void    BitcoinExchange::validatePrice(int price, bool flag) {
    if (price < 0)
        throw NotPosNumberException();
    if (flag && 1000 < price)
        throw toLargePriceException();
}

void    BitcoinExchange::validateDate(int year, int month, int day) {
    std::time_t currentTime = std::time(NULL);
    std::tm* localTime = std::localtime(&currentTime);

    int currentYear = localTime->tm_year + 1900;
    int currentMonth = localTime->tm_mon + 1;
    int currentDay = localTime->tm_mday;

    if (year < 1970 || 2038 < year || month < 1 || 12 < month || day < 1 || 31 < day)
        throw InvalidSeparatorException();
    if (year > currentYear)
        throw InvalidSeparatorException();
    if (year == currentYear && month > currentMonth)
        throw InvalidSeparatorException();
    if (year == currentYear && month == currentMonth && day > currentDay)
        throw InvalidSeparatorException();

    if (((month == 4 || month == 6 || month == 9 || month == 11) && (day < 1 || 30 < day)) ||
		((month == 2) && (((year % 4 == 0) && (year % 100 != 0 || year % 400 == 0)) && (day < 1 || 29 < day))) ||
		((month == 2) && (!((year % 4 == 0) && (year % 100 != 0 || year % 400 == 0)) && (day < 1 || 28 < day)))) {
		throw InvalidSeparatorException();
	}
}

void    BitcoinExchange::validateSeparator(std::istream& is, std::string separator) {
    for (std::string::iterator iter = separator.begin(); iter != separator.end(); ++iter) {
        if (is.get() != *iter)
            throw InvalidSeparatorException();
    }
}

std::map<std::string, double> BitcoinExchange::setBitcoinData(std::ifstream& db, std::string separator) {
    std::map<std::string, double> database;
    std::string line;

    std::getline(db, line);
    while (std::getline(db, line)) {
        std::stringstream stream(line);
        std::string date;
        size_t keySize;
        int year;
        int month;
        int day;
        double price;

        stream >> year;
        stream >> month;
        month *= -1;
        stream >> day;
        day *= -1;
        validateDate(year, month, day);
        validateSeparator(stream, separator);

        stream >> price;
        validatePrice(price, 0);
        if (stream.fail())
			throw InvalidSeparatorException();

        keySize = line.find(DATA_SEP);
        date = line.substr(0, keySize);
        database[date] = price;
    } 
    if (database.size() == 0)
	    throw EmptyFileException();
    return database;
}

void    BitcoinExchange::searchBitcoin(std::ifstream& db, std::string separator){
    std::map<std::string, float> database;
    std::string line;

    std::getline(db, line);
    while (std::getline(db, line)) {
        try {
            std::stringstream stream(line);
            std::string date;
            size_t keySize;
            int year;
            int month;
            int day;
            double price;

            stream >> year;
            stream >> month;
            month *= -1;
            stream >> day;
            day *= -1;
            validateDate(year, month, day);
            validateSeparator(stream, separator);
            
            stream >> price;
            validatePrice(price, 1);
            if (stream.fail())
				throw InvalidSeparatorException();

            keySize = line.find(TARGET_DATA_SEP);
            date = line.substr(0, keySize);
            std::map<std::string, double>::const_iterator iter = bitcoinData.find(date);
            if (iter == bitcoinData.end()) {
				iter = bitcoinData.lower_bound(date);
				if (iter != bitcoinData.begin())
					--iter;
			}
			if (line.substr(0, keySize) < iter->first)
				throw InvalidSeparatorException();
            std::cout
                << line.substr(0, keySize) << " => "
				<< price 
				<< " = " << price * (iter->second) << std::endl;

        } catch(const InvalidSeparatorException& e) {
            std::cerr << RED << "Error: " << e.what() << line << '\n' << RESET;
        } catch(const std::exception& e) {
            std::cerr << RED << "Error: " << e.what() << '\n' << RESET;
        }
    } 
}

const std::map<std::string, double>&    BitcoinExchange::getData() const {
    return bitcoinData;
}

const char * BitcoinExchange::OpenFileException::what() const throw()
{
	return "the file didn't open.";
}

const char * BitcoinExchange::NotPosNumberException::what() const throw()
{
	return "not a positive number.";
}

const char * BitcoinExchange::InvalidSeparatorException::what() const throw()
{
	return "bad input => ";
}

const char * BitcoinExchange::toLargePriceException::what() const throw()
{
	return "too large a number.";
}

const char * BitcoinExchange::EmptyFileException::what() const throw()
{
	return "the file is empty.";
}
