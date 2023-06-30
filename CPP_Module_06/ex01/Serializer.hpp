#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# define RED    "\033[0;31m"
# define GREEN  "\033[1;32m"
# define YELLOW "\033[0;33m"
# define BLUE   "\033[0;34m"
# define RESET  "\033[0m"

# include <iostream>

struct Data {
    std::string name;
};

class Serializer {
    private:
        Serializer();

    public: 
        Serializer(const Serializer& ref);
        Serializer& operator=(const Serializer& ref);
        ~Serializer();

        static uintptr_t serializer(Data* ptr);
        static Data* deserialize(uintptr_t raw);

};

#endif