#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# define RED    "\033[0;31m"
# define GREEN  "\033[1;32m"
# define YELLOW "\033[0;33m"
# define BLUE   "\033[0;34m"
# define RESET  "\033[0m"

#include <algorithm>

template <typename T>
typename T::iterator easyfind(T& container, int value) {
    typename T::iterator iter = std::find(container.begin(), container.end(), value);
    if (iter == container.end())
        throw std::runtime_error("Fail: Value not found...");
    std::cout << GREEN << "Success: Value found!" << std::endl << RESET;
    return iter;
}

#endif