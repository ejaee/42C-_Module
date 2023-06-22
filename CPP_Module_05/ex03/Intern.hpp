#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
    private:

    public:
        Intern();
        Intern(const Intern& i);
        Intern& operator=(const Intern& i);
        ~Intern();

        class FormNotExistException : public std::exception {
            public:
                const char* what() const throw();
        };

        AForm* makeForm(std::string name, std::string target);
};

#endif