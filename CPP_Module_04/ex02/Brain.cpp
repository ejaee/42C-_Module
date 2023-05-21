#include "Brain.hpp"

/* ================= Orthodox Canonical Class Form ================= */

Brain::Brain() {
    for (int idx = 0; idx < 100; idx++) {
        m_ideas[idx] = 'A' + (idx % 26); 
    }
    std::cout << BLUE << "[ Brain ] " << RESET
                << "Default constructed" << std::endl;
}

Brain::Brain(const Brain& brain) {
    for (int idx = 0; idx < 100; idx++)
        m_ideas[idx] = brain.getIdeas(idx);
    std::cout << BLUE << "[ Brain ] " << RESET
                << "Copy constructed" << std::endl;
}

Brain& Brain::operator=(const Brain& brain) {
    if (this != &brain) {
        for (int idx = 0; idx < 100; idx++)
            m_ideas[idx] = brain.getIdeas(idx);
    }
    std::cout << "Assigned" << std::endl;
    return *this;
}

Brain::~Brain() {
    std::cout << BLUE << "[ Brain ] " << RESET
                << "Destructed" << std::endl;
}

/* ================================================================= */

std::string Brain::getIdeas(const int& idx) const {
    return m_ideas[idx];
}

std::ostream&   operator<<(std::ostream& o, const Brain& b) {
    for (int idx = 0; idx < 100; idx++)
        std::cout << idx + 1 << ":  " << b.getIdeas(idx) << std::endl;
    return o;
}