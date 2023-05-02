#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon {

    private:
        std::string m_type;

    public:
        Weapon();
        Weapon(std::string const type);
        ~Weapon();

        const std::string &getType() const;
        void        setType(std::string const type);

};

#endif