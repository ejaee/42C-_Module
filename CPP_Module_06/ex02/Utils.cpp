#include "Utils.hpp"

Base* generate() {
    int random = rand() % 3;

    switch (random) {
        case 0:
            std::cout << RED << "Create A" << std::endl << RESET;
            return new A();
        case 1:
            std::cout << YELLOW << "Create B" << std::endl << RESET;
            return new B();
        case 2:
            std::cout << BLUE<< "Create C" << std::endl << RESET;
            return new C();
        default:
            return NULL;
    }
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << RED << "Pointer A" << std::endl << RESET;
	else if (dynamic_cast<B*>(p))
		std::cout << YELLOW << "Pointer B" << std::endl << RESET;
	else if (dynamic_cast<C*>(p))
		std::cout << BLUE << "Pointer C" << std::endl << RESET;
}

void identify(Base &p) {
    // if (dynamic_cast<A&>(p)) 
    //     std::cout << RED << "A\n" << RESET;
    // else if (dynamic_cast<B&>(p))
    //     std::cout << RED << "B\n" << RESET;
    // else if (dynamic_cast<C&>(p))
    //     std::cout << RED << "C\n" << RESET;
    try {
        A& a = dynamic_cast<A&>(p);
        std::cout << RED << "A\n" << RESET;
        (void)a;
    } catch (const std::exception &e) { }
    try {
        B& b = dynamic_cast<B&>(p);
        std::cout << YELLOW << "B\n" << RESET;
        (void)b;
    } catch (const std::exception &e) { }
    try {
        C& c = dynamic_cast<C&>(p);
        std::cout << BLUE << "C\n" << RESET;
        (void)c;
    } catch (const std::exception &e) { }
}
