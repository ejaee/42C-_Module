#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& ref) {
    *this = ref;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& ref) {
    (void)ref; // A member variable of the class does not exist.
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void    ScalarConverter::convert(const std::string& input) {
    double  inputValue;

    try {
        char *pos = NULL;

        inputValue = std::strtod(input.c_str(), &pos);
        CheckConvertable(pos);
        printResult(input, inputValue);
        std::cout << GREEN << "Run: Convert Success" << RESET << std::endl;

    } catch (...) {
        std::cout << RED << "Error: Convert Failure" << RESET << std::endl;
    }
}

void    ScalarConverter::CheckConvertable(char *pos) {
    if ((*pos) && *pos != 'f')
        throw std::bad_alloc();
}

void    ScalarConverter::convertToChar(std::string input, double inputValue) {
    std::cout << "char: ";
    if (!checkValidValue(input)) {
        std::cout << "impossible\n";
    } else if (inputValue < 33 || 128 < inputValue) {
        std::cout << "Non displayable\n";
    } else {
        std::cout << "'" << static_cast<char>(inputValue) << "'\n";
    }
}

void    ScalarConverter::convertToInt(std::string input, double inputValue) {
    std::cout << "int: ";
    if (!checkValidValue(input)) {
        std::cout << "impossible\n";
    } else if (inputValue > INT_MAX || inputValue < INT_MIN) {
        std::cout << "impossible\n";
    } else {
        std::cout << static_cast<int>(inputValue) << "\n";
    }
}

void    ScalarConverter::convertToFloat(std::string input, double inputValue) {
    std::cout << "float: ";
    if (!checkValidValue(input)) {
        std::cout << input << "f\n";
    } else if (static_cast<int>(inputValue) == inputValue) {
        std::cout << static_cast<float>(inputValue) << ".0f\n";
    } else if (input.find(".") != std::string::npos) {
        std::cout << static_cast<float>(inputValue) << "f\n";
    } else {
        std::cout << static_cast<float>(inputValue) << ".0f\n";
    }
}

void    ScalarConverter:: convertToDouble(std::string input, double inputValue) {
    std::cout << "double: ";
    if (!checkValidValue(input)) {
        std::cout << input << "\n";
    } else if (static_cast<int>(inputValue) == inputValue) {
        std::cout << inputValue << ".0\n";
    } else if (input.find(".") != std::string::npos) {
        std::cout << inputValue << "\n";
    } else {
        std::cout << inputValue << ".0\n";
    }
}

void    ScalarConverter::printResult(std::string input, double inputValue) {
    convertToChar(input, inputValue);
    convertToInt(input, inputValue);
    convertToFloat(input, inputValue);
    convertToDouble(input, inputValue);
}

bool    ScalarConverter::checkValidValue(std::string input) {
    if (input == "nan" || input == "-inf" || input == "+inf" || input == "inf") {
        return false;
    } else {
        return true;
    }
}
