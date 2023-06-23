#include "ScalarConverter.hpp"

int main(int ac, char **av) {
    if (ac != 2)
        std::cerr << RED << "Error: Wrong Arguments\n" << std::endl << RESET;
    else
        ScalarConverter::convert(av[1]);
}
