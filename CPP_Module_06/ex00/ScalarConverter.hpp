#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# define RED    "\033[0;31m"
# define GREEN  "\033[1;32m"
# define YELLOW "\033[0;33m"
# define BLUE   "\033[0;34m"
# define RESET  "\033[0m"

# include <iostream>

class ScalarConverter {
    private:
        static void    printResult(std::string input, double inputValue);
        static void    convertToChar(std::string input, double inputValue);
        static void    convertToInt(std::string input, double inputValue);
        static void    convertToFloat(std::string input, double inputValue);
        static void    convertToDouble(std::string input, double inputValue);

        static bool    checkValidValue(std::string input);
        static void    CheckConvertable(char *pos);

    public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& ref);
        ScalarConverter& operator=(const ScalarConverter& ref);
        ~ScalarConverter();

        static void convert(const std::string& input);
};

#endif