#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# define RED    "\033[0;31m"
# define GREEN  "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE   "\033[0;34m"
# define RESET  "\033[0m"

# include <iostream>

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