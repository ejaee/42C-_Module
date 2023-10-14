#include "MutantStack.hpp"
#include <iostream>
#include <stack>
#include <list>

void waitForTest(std::string nextStep) {
    std::cout << YELLOW << "\n[ Press any key to run the test ]\n" << std::endl << RESET;
    std::cin >> nextStep;
}

int main()
{
    std::cout << YELLOW << "1. MutantStack ver test." << std::endl << RESET;
    waitForTest("");
    {
        MutantStack<int> mstack;
        mstack.push(1);
        mstack.push(2);
        std::cout << "top: " << mstack.top() << std::endl;
        mstack.pop();
        std::cout << "size: " << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(4);
        mstack.push(5);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }

    std::cout << YELLOW << "\n2. list ver test." << std::endl << RESET;
    waitForTest("");
    {
        std::list<int> mstack;
        mstack.push_back(1);
        mstack.push_back(2);
        std::cout << "top: " << mstack.back() << std::endl;
        mstack.pop_back();
        std::cout << "size: " << mstack.size() << std::endl;
        mstack.push_back(3);
        mstack.push_back(4);
        mstack.push_back(5);
        std::list<int>::iterator it = mstack.begin();
        std::list<int>::iterator ite = mstack.end();
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }
    return 0;
}