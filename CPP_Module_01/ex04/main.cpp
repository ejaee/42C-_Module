#include <iostream>
#include <fstream>

int main(int ac, char **av) {
    std::string line;
    File file;

    try {
        
        validation(ac, av);
        file(av[1]);

        while (!file.m_fin.eof() && file.m_fout.good()) {
            std::getline(file.m_fin, line);
            file.replaceString(line, av[2], av[3]);
        }     
    }


    } catch (const std::string message) {
        std::cout << "Error: " << message << std::endl;
    }
}

void    validation(int ac, char **av) {
    if (ac != 4)    throw "invalid input";
    if (av[2].empty()) throw "Invalid s1";
}