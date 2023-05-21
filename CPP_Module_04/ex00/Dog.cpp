#include "Dog.hpp"

/* ================= Orthodox Canonical Class Form ================= */

Dog::Dog() : Animal() {
    m_type = "Dog";
    std::cout << "[ " << m_type << " ] "
                << "Default constructed" << std::endl;   
}

Dog::Dog(const Dog& dog) : Animal() {
    m_type = dog.getType();
    std::cout << "[ " << m_type << " ] "
                << "Copy constructed" << std::endl;   
}

Dog&    Dog::operator=(const Dog& dog) {
    if (this != &dog)
        m_type = dog.getType();
    std::cout << "[ " << m_type << " ] "
                << "Assigned" << std::endl;
    return *this;
}

Animal::~Animal() {
    std::cout << "[ " << m_type << " ] "
                << "Destructed" << std::endl;   
}

/* ================================================================= */

void    Dog::makeSound() const{
    std::cout << "[ " << m_type << " ] " 
                << "Function is not yet implemented" << std::endl;
}