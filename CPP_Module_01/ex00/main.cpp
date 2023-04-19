#include "Zombie.hpp"

int main(){
    Zombie  stack("stack1");
    Zombie  *heap;
    heap = newZombie("heap");
    randomChump("stack2");

    stack.announce();
    heap->announce();
    delete(heap);
    return 0;
}