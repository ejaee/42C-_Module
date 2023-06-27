#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# define RED    "\033[0;31m"
# define GREEN  "\033[1;32m"
# define YELLOW "\033[0;33m"
# define BLUE   "\033[0;34m"
# define RESET  "\033[0m"

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
    public:
        MutantStack() {};
        MutantStack(const MutantStack& ref) {*this = ref;};
        MutantStack& operator=(const MutantStack& ref) {
            if (this != &ref)
                *this = ref;
            return *this;
        }
        ~MutantStack() {};

        typedef typename MutantStack<T>::stack::container_type::iterator iterator;
        iterator begin() {return this->c.begin();}
        iterator end() {return this->c.end();}

        typedef typename MutantStack<T>::stack::container_type::reverse_iterator reverse_iterator;
        reverse_iterator rbegin() {return this->c.rbegin();}
        reverse_iterator rend() {return this->c.rend();}

};

#endif