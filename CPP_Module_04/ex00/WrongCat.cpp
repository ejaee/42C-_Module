#include "WrongCat.hpp"

/* ================= Orthodox Canonical Class Form ================= */

WrongCat::WrongCat() : WrongAnimal() {
    m_type = "WrongCat";
    std::cout << BLUE << "[ " << m_type << " ] " << RESET
                << GREEN << "Default constructed" << RESET << std::endl;   
}

WrongCat::WrongCat(const WrongCat& wrongcat) {
    m_type = wrongcat.getType();
    std::cout << BLUE << "[ " << m_type << " ] " << RESET
                << "Copy constructed" << std::endl;   
}

WrongCat&    WrongCat::operator=(const WrongCat& wrongcat) {
    if (this != &wrongcat)
        m_type = wrongcat.getType();
    std::cout << BLUE << "[ " << m_type << " ] " << RESET
                << "Assigned" << std::endl;
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << BLUE << "[ " << m_type << " ] " << RESET
                << RED << "Destructed" << RESET << std::endl;   
}

/* ================================================================= */

void    WrongCat::makeSound() const{
    std::cout << BLUE << "[ " << m_type << " ] " << RESET
                << YELLOW << "meow! meow!" << RESET << std::endl;
}