#include "Dog.hpp"

/* ================= Orthodox Canonical Class Form ================= */

Dog::Dog() : AAnimal() {
    m_type = "Dog";
    m_brain = new Brain();

    std::cout << BLUE << "[ " << m_type << " ] " << RESET
                << GREEN << "Default constructed" << RESET << std::endl;   
}

Dog::Dog(const Dog& dog) : AAnimal() {
    m_type = dog.getType();
    m_brain = new Brain(*dog.getBrain());

    std::cout << BLUE << "[ " << m_type << " ] " << RESET
                << YELLOW <<  "Copy constructed" << RESET << std::endl;
}

Dog&    Dog::operator=(const Dog& dog) {
    if (this != &dog)
        m_type = dog.getType();

    std::cout << BLUE << "[ " << m_type << " ] " << RESET
                << "Assigned" << std::endl;

    return *this;
}

Dog::~Dog() {
    delete m_brain;
    
    std::cout << BLUE << "[ " << m_type << " ] " << RESET
                << RED << "Destructed" << RESET << std::endl;   
}

/* ================================================================= */

void    Dog::makeSound() const {
    std::cout << BLUE << "[ " << m_type << " ] " << RESET
                << YELLOW << "Woof! Woof" << RESET << std::endl;
}

const   Brain*  Dog::getBrain() const {
    return m_brain;
}