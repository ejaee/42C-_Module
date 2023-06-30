#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

#define FORM_1 "ShrubberyCreationForm"
#define FORM_2 "RobotomyRequestForm"
#define FORM_3 "PresidentialPardonForm"

void waitForTest(std::string nextStep) {
    std::cout << YELLOW << "\n[ Press any key to run the test ]\n" << std::endl << RESET;
    std::cin >> nextStep;
}

void    leaksChecker() {
    system("leaks ex03");
}

int main() {
    atexit(leaksChecker);
    
    Bureaucrat ceo("CEO", 1);
    Bureaucrat staff("Staff", 150);

    std::cout << ceo << staff << std::endl;

    std::cout << YELLOW << "\n[ Test 1: Search known form ]\n" << RESET;
    try {
        Intern intern;
        // AForm *basic = new ShrubberyCreationForm("tree");
        AForm* shrubery = intern.makeForm(FORM_1, "intern form");
        AForm* robotomy = intern.makeForm(FORM_2, "intern form");
        AForm* president = intern.makeForm(FORM_3, "intern form");
    
        std::cout << *shrubery << std::endl;
        std::cout << *robotomy << std::endl;
        std::cout << *president << std::endl;
        
        delete shrubery;
        delete robotomy;
        delete president;

    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET;
    }
    std::cout << YELLOW << "--------------------------------\n" << RESET << std::endl;

    std::cout << YELLOW << "\n[ Test 2: Search unknown form ]\n" << RESET;
    try {
        Intern intern;
        AForm* unknown = intern.makeForm("unknown", "intern form");

        std::cout << *unknown << std::endl;

        delete unknown;
    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET;
    }
    std::cout << YELLOW << "--------------------------------\n" << RESET << std::endl;

}