#include "AMateria.hpp"
#include "ICharacter.hpp"

/* ================= Orthodox Canonical Class Form ================= */

AMateria::AMateria() : m_type(AMA_NAME) {
    std::cout   << BLUE << "[ " << m_type << " ]" << RESET
                << "Default constructed" << std::endl;
}

AMateria::AMateria(const std::string& name) : m_type(name) {
    std::cout   << BLUE << "[ " << m_type << " ]" << RESET
                << "UserDefined constructed" << std::endl;
}

AMateria::AMateria(const AMateria& a) : m_type(a.getType()) {
    std::cout   << BLUE << "[ " << m_type << " ]" << RESET
                << "Copy constructed" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& a) {
    if (this != &a)
        m_type = a.getType();

    std::cout   << BLUE << "[ " << m_type << " ]" << RESET
                << "Assigned" << std::endl;
    return *this;
}

AMateria::~AMateria() {
    std::cout   << BLUE << "[ " << m_type << " ]" << RESET
                << "Destructed" << std::endl;   
}

/* ================================================================= */

const std::string AMateria::getType() const {
    return m_type;
}

void    AMateria::use(const ICharacter& target) {
        std::cout   << BLUE << "[ " << m_type << " ]" << RESET
                << "* use function's interface of " << target.getName() << " *" << std::endl;
}
