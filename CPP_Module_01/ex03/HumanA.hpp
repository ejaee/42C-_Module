#ifndef HUMAN_HPP
# define HUMAN_HPP

#include "Weapon.hpp"

class HumanA {

    private:
        std::string m_name;
        Weapon& m_weapon;

    public:
        HumanA();
        HumanA(std::string const name, Weapon &weapon);
        ~HumanA();

        void    attack() const;
};

#endif