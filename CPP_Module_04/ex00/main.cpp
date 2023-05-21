#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main() {

    std::cout << "\n>>>>>> Case 1: Right Animal! <<<<<<\n" << std::endl;
    {
        const Animal* animal = new Animal();
        const Animal* cat = new Cat();
        const Animal* dog = new Dog();
    
        std::cout << cat->getType() << " " << std::endl;
        std::cout << dog->getType() << " " << std::endl;

        animal->makeSound();
        cat->makeSound();
        dog->makeSound();

        delete animal;
        delete cat;
        delete dog;
    }
    
    std::cout << "\n>>>>>> Case 2: Wrong Animal! <<<<<<\n" << std::endl;
    {
        const WrongAnimal* wrongAnimal = new WrongAnimal();
        const WrongAnimal* wrongCat = new WrongCat();
    
        wrongAnimal->makeSound();
        wrongCat->makeSound();

        delete wrongAnimal;
        delete wrongCat;
    }
    

    return 0;
}