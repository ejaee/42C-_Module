#include "Ice.hpp"

/* ================= Orthodox Canonical Class Form ================= */

Ice::Ice() : AMateria(ICE_TYPE) {
    std::cout   << BLUE << "[ " << m_type << " ] " << RESET
                << "Default constructed" << std::endl;
}

Ice::Ice(const std::string& type) : AMateria(type) {
    std::cout   << BLUE << "[ " << m_type << " ] " << RESET
                << "UserDefined constructed" << std::endl;
}

Ice::Ice(const Ice& i) : AMateria(i.getType()) {
    std::cout   << BLUE << "[ " << m_type << " ] " << RESET 
                << "Copy constructed" << std::endl;
}

Ice& Ice::operator=(const Ice& i) {
    if (this != &i)
        m_type = i.getType();

    std::cout   << BLUE << "[ " << m_type << " ] " << RESET
                << "Assigned" << std::endl;
    return *this;
}

Ice::~Ice() {
    std::cout   << BLUE << "[ " << m_type << " ] " << RESET
                << "Destructed" << std::endl;
}

/* ================================================================= */

AMateria* Ice::clone() const {
    return new Ice();
}


void Ice::use(const ICharacter& target) {
    std::cout   << BLUE << "[ " << m_type << " ] " << RESET
                << YELLOW << "* shoots an ice bolt at " << target.getName() << " *" << RESET << std::endl;
}
