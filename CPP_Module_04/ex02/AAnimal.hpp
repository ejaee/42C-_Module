#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# define RED    "\033[0;31m"
# define GREEN  "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE   "\033[0;34m"
# define RESET  "\033[0m"

# include <iostream>

class AAnimal {
    protected:
        std::string m_type;

    public:
        AAnimal();
        AAnimal(const AAnimal& animal);
        AAnimal& operator=(const AAnimal& animal);
        virtual ~AAnimal();

        std::string    getType() const;
        virtual void    makeSound() const = 0;
};

std::ostream& operator<<(std::ostream& o, const AAnimal& animal);

#endif
