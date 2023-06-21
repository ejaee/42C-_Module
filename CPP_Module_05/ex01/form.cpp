#include "Form.hpp"

Form::Form()
    : m_name("Default"), m_beSigned(false), m_signGrade(70), m_execGrade(70) {

    std::cout << m_name << " Constructor called\n";

}

Form::Form(const std::string& name, const int& signGrade, const int& execGrade)
    : m_name(name), m_beSigned(false), m_signGrade(signGrade), m_execGrade(execGrade) {

    if (signGrade < 1 || execGrade < 1) throw Form::GradeTooHighException();
    if (signGrade > 150 || execGrade > 150) throw Form::GradeTooLowException();

    std::cout << m_name << " Constructor called\n";
}

Form::Form(const Form& f)
    : m_name(f.getName()), m_beSigned(f.getBeSigned()), m_signGrade(f.getSignGrade()), m_execGrade(f.getExecGrade()) {
    
    std::cout << m_name << " Copy Constructor called\n";
}

Form& Form::operator=(const Form& f) {
    if (this != &f) {
        *(const_cast<std::string*>(&m_name)) = f.getName();
        *(const_cast<int*>(&m_signGrade)) = f.getSignGrade();
        *(const_cast<int*>(&m_execGrade)) = f.getExecGrade();
        m_beSigned = f.getBeSigned();
    }

    std::cout << f.getName() << " Copy Assignment called\n";
    return *this;
}

Form::~Form() {
    std::cout << m_name << " Destructor called\n";
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high\n";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low\n";
}

const std::string& Form::getName() const {
    return m_name;
}

const bool& Form::getBeSigned() const {
    return m_beSigned;
}

const int& Form::getSignGrade() const {
    return m_signGrade;
}

const int& Form::getExecGrade() const {
    return m_execGrade;
}

void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > m_signGrade)
        throw GradeTooLowException();
    else if (m_beSigned)
        std::cout << m_name << " aws already signed\n";
    else
        m_beSigned = true;
}

std::ostream& operator<<(std::ostream& ofs, const Form& f) {
    return ofs  << "Form: " << f.getName() << std::endl
                << "BeSign: " << f.getBeSigned() << std::endl
                << "SignGrade: " << f.getSignGrade() << std::endl
                << "ExecGrade: " << f.getExecGrade() << std::endl;
}
