#include "Character.hpp"

/* ================= Orthodox Canonical Class Form ================= */

Character::Character() : m_name("") {
    std::cout   << GREEN << "[ " << m_name << " ]" << RESET
                << "Default constructed" << std::endl;

    for (int idx = 0; idx < AMA_SIZE; idx++)
        m_slot[idx] = NULL;
}

Character::Character(const std::string& name) : m_name(name) {
    std::cout   << GREEN << "[ " << m_name << " ]" << RESET
                << "UserDefined constructed" << std::endl;

    for (int idx = 0; idx < AMA_SIZE; idx++)
        m_slot[idx] = NULL;
}

Character::Character(const Character& c) : m_name(c.getName()) {
    const AMateria* tmp;

    std::cout   << GREEN << "[ " << m_name << " ]" << RESET
                << "Copy constructed" << std::endl;

    for (int idx = 0; idx < AMA_SIZE; idx++) {
        if (m_slot[idx]){
            delete m_slot[idx];
            m_slot[idx] = NULL;
        }
        tmp = c.getAMateria(idx);
        if (tmp)
            m_slot[idx] = tmp->clone();
    }
}

Character& Character::operator=(const Character& c) {
    const AMateria* tmp;
    
    std::cout   << GREEN << "[ " << m_name << " ]" << RESET
                << "Assigned" << std::endl;

    if (this != &c) {
        m_name = c.getName();
        for (int idx = 0; idx < AMA_SIZE; idx++) {
            if (m_slot[idx]){
                delete m_slot[idx];
                m_slot[idx] = NULL;
            }
            tmp = c.getAMateria(idx);
            if (tmp)
                m_slot[idx] = tmp->clone();
        }
    }

    return *this;
}

Character::~Character() {
    std::cout   << GREEN << "[ " << m_name << " ]" << RESET
                << "Destructed" << std::endl;   

    for (int idx = 0; idx < AMA_SIZE; idx++) {
        if (m_slot[idx]) {
            delete m_slot[idx];
            m_slot[idx] = NULL;
        }
    }
}

/* ================================================================= */

const AMateria* Character::getAMateria(const int idx) const {
    return m_slot[idx];
}

const std::string& Character::getName() const {
    return m_name;
}

void    Character::equip(AMateria* m) {
    std::cout   << GREEN << "[ " << m_name << " ]" << RESET
                << "* equip func *";

    if (m) {
        for (int idx = 0; idx < AMA_SIZE; idx++) {
            if (m_slot[idx])
                continue;
            m_slot[idx] = m;

            std::cout << m->getType() << " is equipped correctly on " << m_name << std::endl;
            return ;
        }
        std::cout << RED << m->getType() << " is full " << RESET << std::endl;
    }
    else
        std::cout << RED << "The AMateria you want to equip is empty" << RESET << std::endl;
}

void    Character::unequip(int idx) {
    std::cout   << GREEN << "[ " << m_name << " ]" << RESET
                << "* unequip func *";

    if (0<= idx && idx < AMA_SIZE && m_slot[idx]) {
        m_slot[idx] = NULL;
        std::cout << m_slot[idx] << " is unequipped correctly on " << m_name << std::endl;
    }
    else
        std::cout   << GREEN << "[ " << m_name << " ]" << RESET
                    << "This slot is empty or inaccessible idx";    

}

void    Character::use(int idx, const ICharacter& target) {
    if (0 <= idx && idx < AMA_SIZE && m_slot[idx])
        m_slot[idx]->use(target);
    else
        std::cout   << GREEN << "[ " << m_name << " ]" << RESET
                    << "This slot is empty or inaccessible idx";
}

