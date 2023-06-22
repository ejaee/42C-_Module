#include "Intern.hpp"

#define FORM_1 0
#define FORM_2 24
#define FORM_3 46

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
    std::string formList("ShrubberyCreationForm | RobotomyRequestForm | PresidentialPardonForm");
    AForm* result = NULL;

    if (name.length() == 0)
        throw Intern::FormNotExistException();
    switch (formList.find(name)) {
        case FORM_1:
            result = new ShrubberyCreationForm(target);
            break;
        case FORM_2:
            result = new RobotomyRequestForm(target);
            break;
        case FORM_3:
            result = new PresidentialPardonForm(target);
            break;
        default:
            throw Intern::FormNotExistException();
    }
    std::cout << GREEN << "Success! " << name << std::endl << RESET;
    return result;
}