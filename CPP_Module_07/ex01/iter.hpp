#ifndef ITER_HPP
# define ITER_HPP

# define RED    "\033[0;31m"
# define GREEN  "\033[1;32m"
# define YELLOW "\033[0;33m"
# define BLUE   "\033[0;34m"
# define RESET  "\033[0m"

#include <iostream>

template <typename T>
void iter(T* arr, int len, void (*func)(T&)) {
    for (int i = 0; i < len; i++)
        func(arr[i]);
}

template <typename T>
void printArr(T& data) {
    std::cout << GREEN << data << " " << RESET;
}

#endif
