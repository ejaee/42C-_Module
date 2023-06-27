#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# define RED    "\033[0;31m"
# define GREEN  "\033[1;32m"
# define YELLOW "\033[0;33m"
# define BLUE   "\033[0;34m"
# define RESET  "\033[0m"

template<typename T>
void swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
T min(T &a, T &b) {
    if (a > b)
        return b;
    return a;
}

template<typename T>
T max(T &a, T &b) {
    if (a < b)
        return b;
    return a;
}

#endif