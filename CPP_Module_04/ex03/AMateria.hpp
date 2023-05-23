#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# define AMA_NAME "amateria"
# define AMA_SIZE 4

# define RED    "\033[0;31m"
# define GREEN  "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE   "\033[0;34m"
# define RESET  "\033[0m"

# include <iostream>

class ICharacter;

class AMateria {
    protected:
        std::string m_type;

    public:
        AMateria();
        AMateria(const std::string& name);
        AMateria(const AMateria& a);
        AMateria& operator=(const AMateria& a);
        virtual ~AMateria();

        const std::string  getType() const;

        virtual AMateria* clone() const = 0;
        virtual void use(const ICharacter& target);
};

#endif
