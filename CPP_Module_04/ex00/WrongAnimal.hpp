#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# define RED    "\033[0;31m"
# define GREEN  "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE   "\033[0;34m"
# define RESET  "\033[0m"

# include <iostream>

class WrongAnimal {
    protected:
        std::string m_type;

    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal& wrongAnimal);
        WrongAnimal& operator=(const WrongAnimal& wrongAnimal);
        virtual ~WrongAnimal();  

        std::string    getType() const;
        // virtual void    makeSound() const;
        void    makeSound() const;
};

std::ostream& operator<<(std::ostream& o, const WrongAnimal& animal);

#endif