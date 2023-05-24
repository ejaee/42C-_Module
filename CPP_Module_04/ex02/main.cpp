#include "Dog.hpp"
#include "Cat.hpp"

int main() {

    std::cout << "\n>>>>>> Case 1: normal Animal! <<<<<<\n" << std::endl;
    {
        const AAnimal* a = new Cat();	// new for abstract class
        const AAnimal* b = new Dog();	// new for abstract class

		const Dog* c = new Dog();		// new for getBrain()

        a->makeSound();
        b->makeSound();
        c->makeSound();

		std::cout << std::endl;

        for (int idx = 0; idx < 4; idx++)
            std::cout << "Thinking... " << c->getBrain()->getIdeas(idx) << std::endl;

		std::cout << std::endl;

        delete a;
        delete b;
    }


	std::cout << "\n>>>>>> Case 2: Deep Animal! <<<<<<\n" << std::endl;
	{
		AAnimal* animals[4];
		Dog*  dog;

		for (int idx = 0; idx < 4; idx++) {
			if (!(idx % 2))
				animals[idx] = new Cat();
    		else
				animals[idx] = new Dog();
	
		}

		dog = new Dog((*dynamic_cast<Dog *>(animals[1])));
		for (int idx = 0; idx < 4; idx++)
			delete animals[idx];

		std::cout << std::endl;

		std::cout << YELLOW << *dog->getBrain() << RESET << std::endl;

		
		delete dog;
	}

    return 0;
}
