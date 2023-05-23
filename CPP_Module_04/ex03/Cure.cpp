#include "Cure.hpp"

/* ================= Orthodox Canonical Class Form ================= */

Cure::Cure() : AMateria(CURE_TYPE) {
    std::cout   << BLUE << "[ " << m_type << " ]" << RESET
                << "Default constructed" << std::endl;
}

Cure::Cure(const std::string& type) : AMateria(type) {
    std::cout   << BLUE << "[ " << m_type << " ]" << RESET
                << "UserDefined constructed" << std::endl;
}

Cure::Cure(const Cure& c) : AMateria(c.getType()) {
    std::cout   << BLUE << "[ " << m_type << " ]" << RESET 
                << "Copy constructed" << std::endl;
}

Cure& Cure::operator=(const Cure& i) {
    if (this != &i)
        m_type = i.getType();

    std::cout   << BLUE << "[ " << m_type << " ]" << RESET
                << "Assigned" << std::endl;
    return *this;
}

Cure::~Cure() {
    std::cout   << BLUE << "[ " << m_type << " ]" << RESET
                << "Destructed" << std::endl;
}

/* ================================================================= */

AMateria* Cure::clone() const {
    return new Cure();
}


void Cure::use(const ICharacter& target) {
    std::cout   << BLUE << "[ " << m_type << " ]" << RESET
                << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
