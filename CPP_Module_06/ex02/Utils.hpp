#ifndef UTILS_HPP
# define UTILS_HPP

# define RED    "\033[0;31m"
# define GREEN  "\033[1;32m"
# define YELLOW "\033[0;33m"
# define BLUE   "\033[0;34m"
# define RESET  "\033[0m"

#include "Base.hpp"
#include <cstdlib>

Base*    generate();
void     identify(Base* p);
void     identify(Base& p);

#endif
