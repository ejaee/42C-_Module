#include "Span.hpp"

Span::Span() {};

Span::Span(const unsigned int N) {
    _intVector.reserve(N);
};

Span::Span(const Span& ref) {
    _intVector.reserve(ref.getVector().capacity());
    std::copy(ref.getVector().begin(), ref.getVector().end(), std::back_inserter(_intVector));
}

Span& Span::operator=(const Span& ref) {
    if  (this != &ref){
        _intVector.reserve(ref.getVector().capacity());
        std::copy(ref.getVector().begin(), ref.getVector().end(), std::back_inserter(_intVector));
    }
    return *this;
}

Span::~Span() {
    std::vector<int>().swap(_intVector);
}

void    Span::addNumber(int num) {
    if (_intVector.size() == _intVector.capacity()) throw CanNoLongerBeSavedException();
    _intVector.push_back(num);
}

std::vector<int> Span::sortVector() const {
    std::vector<int> sorted(_intVector);
    std::sort(sorted.begin(), sorted.end());
    return sorted;    
}

int Span::getShortestSpan(std::vector<int> sortedVector) {
    std::vector<int>::const_iterator iter = sortedVector.begin();
    int min = INT_MAX;
    int prev = *iter;
    iter++;
    while (iter != sortedVector.end()) {
        if (*iter - prev < min)
            min = *iter - prev;
        prev = *(iter++);
    }
    return min;
}

int Span::shortestSpan() {
    if (_intVector.size() < 2) throw std::runtime_error("Not enough element");
    std::vector<int> sortedVector = sortVector();
    return getShortestSpan(sortedVector);
}

int Span::longestSpan() {
    if (_intVector.size() < 2) throw std::runtime_error("Not enough element");
    return *std::max_element(_intVector.begin(), _intVector.end()) - *std::min_element(_intVector.begin(), _intVector.end());
}

const std::vector<int>& Span::getVector() const {
    return _intVector;
}

const char* Span::CanNoLongerBeSavedException::what() const throw() {
    return "Span can no longer be saved any number";
}