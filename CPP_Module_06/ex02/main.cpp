#include "Utils.hpp"

int main() {
    srand(time(NULL));
    
    Base* randomBase1 = generate();
    identify(randomBase1);
    identify(*randomBase1);

    Base* randomBase2 = generate();
    identify(randomBase2);
    identify(*randomBase2);

    Base* randomBase3 = generate();
    identify(randomBase3);
    identify(*randomBase3);


    
    
}
