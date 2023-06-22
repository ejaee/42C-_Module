#include "AForm.hpp"

AForm::AForm()
    : m_name("Default"), m_signStatus(false), m_signGrade(70), m_execGrade(70) {

    std::cout << m_name << " Constructor called\n";

}

AForm::AForm(const std::string& name, const int& signGrade, const int& execGrade)
    : m_name(name), m_signStatus(false), m_signGrade(signGrade), m_execGrade(execGrade) {

    if (signGrade < 1 || execGrade < 1) throw AForm::GradeTooHighException();
    if (signGrade > 150 || execGrade > 150) throw AForm::GradeTooLowException();

    std::cout << m_name << " Constructor called\n";
}

AForm::AForm(const AForm& f)
    : m_name(f.getName()), m_signStatus(f.getSignStatus()), m_signGrade(f.getSignGrade()), m_execGrade(f.getExecGrade()) {
    
    std::cout << m_name << " Copy Constructor called\n";
}

AForm& AForm::operator=(const AForm& f) {
    if (this != &f) {
        *(const_cast<std::string*>(&m_name)) = f.getName();
        *(const_cast<int*>(&m_signGrade)) = f.getSignGrade();
        *(const_cast<int*>(&m_execGrade)) = f.getExecGrade();
        m_signStatus = f.getSignStatus();
    }

    std::cout << f.getName() << " Copy Assignment called\n";
    return *this;
}

AForm::~AForm() {
    std::cout << m_name << " Destructor called\n";
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high\n";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low\n";
}

const char* AForm::NotSignedException::what() const throw() {
    return "Form is not signed";
}

const char* AForm::NoPermissionException::what() const throw() {
    return "Can't sign because of low grade";
}

const char* AForm::FileException::what() const throw() {
    return "File exception";
}

const std::string& AForm::getName() const {
    return m_name;
}

const bool& AForm::getSignStatus() const {
    return m_signStatus;
}

const int& AForm::getSignGrade() const {
    return m_signGrade;
}

const int& AForm::getExecGrade() const {
    return m_execGrade;
}

void    AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > m_signGrade)
        throw GradeTooLowException();
    else if (m_signStatus)
        std::cout << RED << m_name << " was already signed\n" << RESET;
    else{
        std::cout << GREEN << m_name << " was signed successfully.\n" << RESET;
        m_signStatus = true;
    }
}

void    AForm::checkExecutable(const Bureaucrat& b) const {
    if (getSignStatus() == false) throw AForm::NotSignedException();
    if (getExecGrade() < b.getGrade()) throw AForm::NoPermissionException();
}

std::ostream& operator<<(std::ostream& ofs, const AForm& f) {
    return ofs  << "Form: " << f.getName() << std::endl
                << "BeSign: " << f.getSignStatus() << std::endl
                << "SignGrade: " << f.getSignGrade() << std::endl
                << "ExecGrade: " << f.getExecGrade() << std::endl;
}
