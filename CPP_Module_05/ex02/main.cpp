#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void waitForTest(std::string nextStep) {
    std::cout << YELLOW << "\n[ Press any key to run the test ]\n" << std::endl << RESET;
    std::cin >> nextStep;
}

int main() {
    Bureaucrat ceo("CEO", 1);
    Bureaucrat staff("Staff", 150);

    std::cout << ceo << staff << std::endl;

    /**
     * Use abstract class
     * 
     * Let's take advantage of abstract classes to test each of our forms
     * You only need to modify the child class without modifying anything else!
     * 
     * [Copy List]
     * 
     * ShrubberyCreationForm
     * RobotomyRequestForm
     * PresidentialPardonForm
    */

    std::cout << YELLOW << "\n[ Test 1: Staff tries to sign the Form ]\n" << RESET;
    waitForTest("");
    try {
        AForm *basic = new ShrubberyCreationForm("tree");
        std::cout << *basic << std::endl;
        
        std::cout << BLUE << "\n[Before]\n" << RESET;
        std::cout << BLUE << *basic << RESET;

        staff.signForm(*basic);
        std::cout << BLUE << "\n[After]\n" << RESET;
        std::cout << BLUE << *basic << RESET;
        staff.executeForm(*basic);
    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET;
    }

    std::cout << YELLOW << "\n[ Test 2: ceo tries to sign the Form ]\n" << RESET;
    waitForTest("");
    try {
        AForm *basic = new ShrubberyCreationForm("tree");
        std::cout << *basic << std::endl;
        
        std::cout << BLUE << "\n[Before]\n" << RESET;
        std::cout << BLUE << *basic << RESET;

        ceo.signForm(*basic);
        std::cout << BLUE << "\n[After]\n" << RESET;
        std::cout << BLUE << *basic << std::endl << RESET;

        ceo.executeForm(*basic);

        std::cout << "\nCheck for duplicates despite signatures" << std::endl;
        ceo.signForm(*basic);
    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET;
    }

}