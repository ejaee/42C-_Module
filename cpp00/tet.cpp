#include <iostream>

int main(int ac, char **av) {

    // if (ac <2)
    //     std::cout << "hello " << "ejae" << std::endl;
    // else {
    //     for (int i = 0; i < ac; i++) {
    //         for (int j = 0; av[i][j] != '\0'; j++) {
    //             std::cout << (char)std::toupper(av[i][j]);
    //         }
    //         std::cout << std::endl;
    //     }
    // }

    std::string str[5];

    str[0] = "a";
    str[1] = "b";
    str[2] = "c";
    str[3] = "d";
    str[4] = "e";

    std::cout << *str << std::endl;
    return 0;
}