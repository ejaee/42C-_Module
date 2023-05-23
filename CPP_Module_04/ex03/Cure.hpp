#ifndef CURE_HPP
# define CURE_HPP

# define CURE_TYPE "cure"

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria {
    private:

    public:
        Cure();
        Cure(const std::string& name);
        Cure(const Cure& i);
        Cure& operator=(const Cure& i);
        ~Cure();

        AMateria* clone() const;
        void use(const ICharacter& target);
};

# endif