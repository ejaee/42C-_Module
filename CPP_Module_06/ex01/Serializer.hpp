#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

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