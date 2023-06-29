#include "RPN.hpp"

int main(int ac, char** av) {
    if (ac != 2) {
        std::cout << "Error" << std::endl;
        return 1;
    }

    RPN rpn(av[1]);
    rpn.run();
    // try
    // {
    //     Rpn rpn(av[1]);
    //     std::cout << rpn.calc() << std::endl;
    // }
}