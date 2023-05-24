#include "MateriaSource.hpp"

/* ================= Orthodox Canonical Class Form ================= */

MateriaSource::MateriaSource() {
    std::cout   << "Default constructed" << std::endl;

    for (int idx = 0; idx < AMA_SIZE; idx++)
        m_slot[idx] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& ms) {
    const AMateria* tmp;

    std::cout   << "Copy constructed" << std::endl;

    for (int idx = 0; idx < AMA_SIZE; idx++) {
        if (m_slot[idx]){
            delete m_slot[idx];
            m_slot[idx] = NULL;
        }
        tmp = ms.getAMateria(idx);
        if (tmp)
            m_slot[idx] = tmp->clone();
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& ms) {
    const AMateria* tmp;

    std::cout   << "Assigned" << std::endl;

    if (this != &ms) {
        for (int idx = 0; idx < AMA_SIZE; idx++) {
            if (m_slot[idx]){
                delete m_slot[idx];
                m_slot[idx] = NULL;
            }
            tmp = ms.getAMateria(idx);
            if (tmp)
                m_slot[idx] = tmp->clone();
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    std::cout   << "Destructed" << std::endl;

    for (int idx = 0; idx < AMA_SIZE; idx++) {
        if (m_slot[idx]) {
            delete m_slot[idx];
            m_slot[idx] = NULL;
        }
    }
}

/* ================================================================= */

const AMateria* MateriaSource::getAMateria(const int idx) const {
    return m_slot[idx];
}

void    MateriaSource::learnMateria(AMateria* m) {
    if (m) {
        for (int idx = 0; idx < AMA_SIZE; idx++) {
            if (m_slot[idx])
                continue;
            m_slot[idx] = m;

            std::cout << m->getType() 
                    << " is learned correctly at index: [" << idx + 1 <<  "/" << AMA_SIZE << "]" << std::endl;
            return ;
        }
        std::cout << m->getType() 
                << " not learned correctly. " << RED << "[Out of storage space]" << std::endl;
        delete m;
    }
    else
        std::cout << RED << "The AMateria you want to learn is empty" << RESET << std::endl;
}

AMateria*   MateriaSource::createMateria(const std::string& type) {
    for (int idx = 0; idx < AMA_SIZE; idx++) {
        if (m_slot[idx] && m_slot[idx]->getType() == type) {
            return m_slot[idx]->clone();
        }
    }

    std::cout << RED << type << " is not matched" << RESET << std::endl;
    return NULL;
}