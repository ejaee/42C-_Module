#include "FileDto.hpp"

void    validation(int ac, char **av) {
    std::string str = av[2];
    if (ac != 4)    throw "invalid input";
    if (str.empty()) throw "Invalid s1";
}

int main(int ac, char **av) {
    std::string line;

    try {
        validation(ac, av);
        FileDto fileDto(av[1]);

        while (!fileDto.getFin().eof() && fileDto.getFout().good()) {
            std::getline(fileDto.getFin(), line);
            fileDto.replaceString(line, av[2], av[3]);
        }     
    }   catch (const std::string message) {
        std::cout << "Error: " << message << std::endl;
    }
}
