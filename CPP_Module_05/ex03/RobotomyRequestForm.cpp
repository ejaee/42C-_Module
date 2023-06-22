#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("robotomy", 72, 45), m_target("Unspecified") {
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("robotomy", 72, 45), m_target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& f)
    : AForm(f), m_target(f.getTarget()){
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& f) {
    if (this != &f) {
        dynamic_cast<AForm&>(*this) = dynamic_cast<const AForm&>(f);
        m_target = f.getTarget();
    }
    return  *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {

}

std::string RobotomyRequestForm::getTarget() const {
    return  m_target;
}

void    RobotomyRequestForm::execute(const Bureaucrat& b) const {
    checkExecutable(b);

    std::cout << "Start robotomy [success rate: "<< BLUE << "50%" << RESET <<" ]";
    std::cout << BLUE << "drrrrrrrr.... drrrr....\n" << RESET;

    int result;
    srand(time(NULL));
    result = rand();
    if (result % 2 == 0)
        std::cout << GREEN << m_target << " has been robotomized\n" << RESET;
    else
        std::cout << RED << m_target << " robotomy failed\n" << RESET;
}