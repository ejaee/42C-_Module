#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <algorithm>

int main() {

    std::string test;
    std::string test2;

    // std::cout << "input! 2 " << std::endl;

    int t;
    while(1) {
        std::cin >> t;
        std::cout << "입력 :: " << t << std::endl;
        if (t == 0) break;
    }

    // getline(std::cin, test2);
    // std::getline(std::cin, test);
    
    // std::string test3 = "hello";
    // std::cout << test3 << std::endl;
    // std::transform(test3.begin(), test3.end(), test3.begin(), ::toupper);
    // std::cout << test3 << std::endl;

    // std::cout << std::string(10,'=') << std::endl;
    // std::cout << test << std::endl;
    // std::cout << test2 << std::endl;

    // int number;

    // number = std::atoi(test.c_str());
    // std::cout << std::endl << std::string(10,'=') << std::endl;
    // std::cout << std::substr(0,9) + "." << std::endl;
    // std::cout << "1234567890" << std::endl;
    // std::cout << std::setw(10) << number;
    // std::cout << "::" << std::endl;

}