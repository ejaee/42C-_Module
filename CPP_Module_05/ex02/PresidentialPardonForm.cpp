#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("presidential pardon", 25, 5), m_target("Unspecified") {
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("presidential pardon", 25, 5), m_target(target) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& f)
    : AForm(f), m_target(f.getTarget()){
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& f) {
    if (this != &f) {
        dynamic_cast<AForm&>(*this) = dynamic_cast<const AForm&>(f);
        m_target = f.getTarget();
    }
    return  *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {

}

std::string PresidentialPardonForm::getTarget() const {
    return  m_target;
}

void    PresidentialPardonForm::execute(const Bureaucrat& b) const {
    checkExecutable(b);

    std::cout << GREEN << m_target << " has been pardoned by Zaphod Beeblebrox." << std::endl << RESET;
}