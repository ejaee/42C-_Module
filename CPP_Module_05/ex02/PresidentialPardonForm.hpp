#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    private:
        std::string m_target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string& m_target);
        PresidentialPardonForm(const PresidentialPardonForm& f);
        PresidentialPardonForm& operator=(const PresidentialPardonForm&  f);
        ~PresidentialPardonForm();

        std::string getTarget() const;

        void execute(const Bureaucrat& b) const;
};

#endif