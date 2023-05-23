#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int main() {
/* ====================================================================*/
    
    std::cout << YELLOW << "\nCreate MateriaSource : [Ice], [Cure]\n" << RESET << std::endl;

    IMateriaSource* src = new MateriaSource();

    std::cout << std::endl;

    src->learnMateria(new Ice());
    std::cout << std::endl;
    src->learnMateria(new Cure());
    std::cout << std::endl;
    src->learnMateria(new Ice());
    std::cout << std::endl;
    src->learnMateria(new Cure());
    std::cout << std::endl;
    src->learnMateria(new Ice());

/* ====================================================================*/
    
    std::cout << YELLOW << "\nCreate User 1: [me]\n" << RESET << std::endl;

    ICharacter* me = new Character("me");
    
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    tmp = src->createMateria("cure");

    me->unequip(1); // valid message
    me->unequip(2); // invalid message


/* ====================================================================*/
    
    std::cout << YELLOW << "\nCreate User 2: [bob]\n" << RESET << std::endl;

    ICharacter* bob = new Character("bob");
    
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
    
    return 0;
/* ====================================================================*/
}
