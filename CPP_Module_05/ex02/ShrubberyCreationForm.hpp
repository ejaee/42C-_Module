#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
    private:
        std::string m_target;
        ShrubberyCreationForm();
    public:
        ShrubberyCreationForm(const std::string& m_target);
        ShrubberyCreationForm(const ShrubberyCreationForm& f);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm&  f);
        ~ShrubberyCreationForm();

        std::string getTarget() const;

        void execute(const Bureaucrat& b) const;
};

#endif