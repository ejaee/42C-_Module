#ifndef ARRAY_HPP
# define ARRAY_HPP

# define RED    "\033[0;31m"
# define GREEN  "\033[1;32m"
# define YELLOW "\033[0;33m"
# define BLUE   "\033[0;34m"
# define RESET  "\033[0m"

#include <iostream>
#include <exception>

template <typename T>
class Array {
    private:
        T* arr;
        unsigned int len;

    public:

        Array() : arr(new T[0]), len(0) {};
        Array(unsigned int n) : arr(new T[n]), len(n) {};
        Array(const Array& ref) : arr(new T[ref.size()]), len(ref.size()) {
            for (unsigned int idx = 0; idx < len; idx++)
                arr[idx] = ref[idx];
        }
        Array& operator=(const Array& ref) {
            if (this != &ref) {
                arr = new T[ref.size()];
                len = ref.size();
                for (unsigned int idx = 0; idx < len; idx++)
                    arr[idx] = ref[idx];
            }
            return *this;
        }
        ~Array() {
            if (arr != NULL)
                delete[] arr;
        }

        class OutOfBounds : public std::exception {
            public:
                const char* what() const throw() {
                    return "Array index out of bounds";
                }
        };

        class DiffValuesException : public std::exception {
            public:
                const char* what() const throw() {
                    return "Different values were stored in the two strings.";
                }
        };

        T& operator[](const unsigned int idx) const {
            if (idx >= len) throw OutOfBounds();
            return arr[idx];
        }

        unsigned int size() const {
            return len;
        }

};

#endif