#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal {
    protected:
        std::string m_type;

    public:
        Animal();
        Animal(const Animal& animal);
        Animal& operator=(const Animal& animal);
        virtual ~Animal();

        std::string    getType() const;
        virtual void    makeSound() const;
};

std::ostream& operator<<(std::ostream& o, const Animal& animal);

#endif