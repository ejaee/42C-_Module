#include "FileDto.hpp"

void    validateInput(int ac, char **av) {
    std::string str = av[2];

    if (ac != 4)        throw std::string("invalid input");
    if (str.empty())    throw std::string("Invalid s1");
}

int main(int ac, char **av) {
    std::string buf;

    try {
        validateInput(ac, av);
        FileDto fileDto(av[1]);

        // while (!fileDto.getFin().eof() && fileDto.getFout().good()) { // 파일이 비어있을 때 한번 돈다
        while (std::getline(fileDto.getFin(), buf) && fileDto.getFout().good()) {
            fileDto.replaceString(buf, av[2], av[3]);
        }     
        return 0;
    }   catch (const std::string message) {
        std::cerr << "Error: " << message << std::endl;
        return 1;
    }
}
