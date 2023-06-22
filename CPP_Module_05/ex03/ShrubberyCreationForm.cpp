#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("shrubbery", 145, 137), m_target("Unspecified") {
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("shrubbery", 145, 137), m_target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& f)
    : AForm(f), m_target(f.getTarget()){
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& f) {
    if (this != &f) {
        dynamic_cast<AForm&>(*this) = dynamic_cast<const AForm&>(f);
        m_target = f.getTarget();
    }

    return  *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}

std::string ShrubberyCreationForm::getTarget() const {
    return  m_target;
}

void    ShrubberyCreationForm::execute(const Bureaucrat& b) const {
    checkExecutable(b);
    
    std::ofstream writeFile(m_target + "_shrubbery", std::ios::out | std::ios::app);
    std::string asciiTree = "\
               ,@@@@@@@,\n\
       ,,,.   ,@@@@@@/@@,  .oo8888o.\n\
    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n\
   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n\
   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n\
   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n\
   `&%\\ ` /%&'    |.|        \\ '|8'\n\
       |o|        | |         | |\n\
       |.|        | |         | |\n\
___ \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n";

    if (!writeFile.is_open())
        throw FileException();
    writeFile << asciiTree;
    writeFile.close();
    std::cout << GREEN << "The file was created successfully." << std::endl << RESET;
}