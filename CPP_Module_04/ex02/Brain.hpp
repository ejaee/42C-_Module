#ifndef BRAIN_HPP
# define BRAIN_HPP

# define RED    "\033[0;31m"
# define GREEN  "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE   "\033[0;34m"
# define RESET  "\033[0m"

#include <iostream>

class Brain {
    private:
        std::string    m_ideas[100];

    public:
        Brain();
        Brain(const Brain& brain);
        Brain&  operator=(const Brain& brain);
        ~Brain();

        std::string getIdeas(const int& idx) const;
};

std::ostream&   operator<<(std::ostream& o, const Brain& b);

#endif