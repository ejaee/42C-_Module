#ifndef ICE_HPP
# define ICE_HPP

# define ICE_TYPE "ice"

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria {
    private:

    public:
        Ice();
        Ice(const std::string& name);
        Ice(const Ice& i);
        Ice& operator=(const Ice& i);
        ~Ice();

        AMateria* clone() const;
        void use(const ICharacter& target);
};

# endif