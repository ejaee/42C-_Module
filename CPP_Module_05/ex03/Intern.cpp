#include "Intern.hpp"

Intern::Intern() {

}

Intern::Intern(const Intern& i) {
    (*this) = i;
}

Intern& Intern::operator=(const Intern& i) {
    if (this != &i)
        (*this) = i;
    return *this;
}

Intern::~Intern() {

}

const char* Intern::FormNotExistException::what() const throw() {
    return "Invaild form name\n";
}

AForm* Intern::makeForm(std::string name, std::string target) {
    std::string formList("shrubbery creation | robotomy creation | presidential pardon");
    AForm* result = NULL;

    if (name.length() == 0)
        throw Intern::FormNotExistException();
    switch (formList.find(name)) {
        case 0:
            result = new ShrubberyCreationForm(target);
            break;
        case 21:
            result = new RobotomyRequestForm(target);
            break;
        case 41:
            result = new PresidentialPardonForm(target);
            break;
        default:
            throw Intern::FormNotExistException();
    }
    return result;
}