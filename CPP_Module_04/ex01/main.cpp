#include "Dog.hpp"
#include "Cat.hpp"

int main() {

    std::cout << "\n>>>>>> Case 1: Right Animal! <<<<<<\n" << std::endl;
    {
        const Animal* a = new Cat();
        const Animal* b = new Cat();
        const Dog* c = new Dog();

        a->makeSound();
        b->makeSound();
        c->makeSound();

        for (int idx = 0; idx < 4; idx++)
            std::cout << "Thinking... " << c->getBrain()->getIdeas(idx) << std::endl;

        delete a;
        delete b;
        delete c;
    }

    return 0;
}

// HOW CAN CHECK LEAKS?! system("leaks a.out"); IS RUN??