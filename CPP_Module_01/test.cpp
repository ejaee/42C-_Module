#include <iostream>

class Test{
    int a;

    public:
        int getA();    
};

int Test::getA(){
    return a;
};

int main(){
    // Test* test = new Test[3];

    // for(int i = 0; i < 3; i++){
    //     std::cout << test[i].getA() << std::endl;
    // }

    Test* test[3];

    for (int i = 0; i < 3; i++){
        test[i] = Test();
        test[i].getA();
    }

    
    return 0;
}
