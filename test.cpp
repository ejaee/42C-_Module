#include <iostream>

# define RED    "\033[0;31m"
# define GREEN  "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE   "\033[0;34m"
# define RESET  "\033[0m"

class P {
        int name;

    public:
        P(){ std::cout << "P class create" << std::endl; }
        ~P(){  std::cout << "P class delete" << std::endl; }

        virtual void    what() { std::cout << RED << "P class's what()" << RESET << std::endl; }


};

class C : public P {
    
    public:
        C() : P(){ std::cout << "C class create" << std::endl; }
        ~C() {std::cout << "C class delete" << std::endl;}

        void    what(){std::cout << YELLOW << "C class's what()" << RESET << std::endl;}
};

int main() {
    P p;
    C c;

    P *pp = &p;
    P *pc = &c;

    pp->what();
    pc->what();

}