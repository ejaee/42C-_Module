#ifndef SPAN_HPP
# define SPAN_HPP

# define RED    "\033[0;31m"
# define GREEN  "\033[1;32m"
# define YELLOW "\033[0;33m"
# define BLUE   "\033[0;34m"
# define RESET  "\033[0m"

#include <iostream>
#include <vector>

class Span {
    private:
        std::vector<int> _intVector;

        std::vector<int> sortVector() const;
        int getShortestSpan(std::vector<int> sortedVector);
    public:
        Span();
        Span(const unsigned int N);
        Span(const Span& ref);
        Span& operator=(const Span& ref);
        ~Span();

        void    addNumber(int num);
        void    addNumbersAsManyAs(int num);
        int     shortestSpan();
        int     longestSpan();

        const std::vector<int>& getVector() const;    

        class CanNoLongerBeSavedException : public std::exception {
            public:
                const char* what() const throw();
        };

};

#endif