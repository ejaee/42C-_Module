#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
    : m_name("Default"), m_grade(1) {

    std::cout << m_name << " Constructor called\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade) 
    : m_name(name), m_grade(grade) {

    if (m_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if(m_grade > 150)
        throw Bureaucrat::GradeTooLowException();

    std::cout << m_name << " Constructor called\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& b) 
    : m_name(b.getName()), m_grade(b.getGrade()){
    
    if (m_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if(m_grade > 150)
        throw Bureaucrat::GradeTooLowException();

    std::cout << m_name << " Copy Constructor called\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& b) {
    if (this != &b) {
        *(const_cast<std::string*>(&m_name)) = b.getName();
        m_grade = b.getGrade();
    }

    std::cout << b.getName() << " Copy Assignment called\n";
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << m_name << " Destructor called\n";
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low\n";
}

const std::string& Bureaucrat::getName() const {
    return m_name;
}

const int& Bureaucrat::getGrade() const {
    return m_grade;
}

void    Bureaucrat::increaseGrade() {
    if (m_grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    m_grade--;
}

void    Bureaucrat::decreaseGrade() {
    if (m_grade >= 150)
        throw Bureaucrat::GradeTooLowException();
    m_grade++;
}

void    Bureaucrat::signForm(AForm& f) const {
    try {
        f.beSigned(*this);
    } catch(std::exception& e) {
        std::cerr << RED << "Sign Error: " << e.what() << RESET;
    }
}

void    Bureaucrat::executeForm(const AForm& f) const {
    try {
        f.execute(*this);
        std::cout << "Execution Form: " << f.getName() << " | Executor: " << m_name << std::endl;
    } catch (std::exception& e) {
        std::cerr << RED << m_name << "  cannot be executed due to "
        << e.what() << std::endl << RESET;
    }
}

std::ostream& operator<<(std::ostream& ofs, const Bureaucrat& b) {
    return  ofs << GREEN << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << RESET << std::endl;
}
