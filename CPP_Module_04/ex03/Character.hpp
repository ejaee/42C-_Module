#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
    private:
        std::string m_name;
        AMateria*   m_slot[AMA_SIZE];

    public:
        Character();
        Character(const std::string& name);
        Character(const Character& name);
        Character& operator=(const Character& name);
        ~Character();

        const AMateria* getAMateria(const int idx) const;

        const std::string& getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, const ICharacter& target);
};

# endif