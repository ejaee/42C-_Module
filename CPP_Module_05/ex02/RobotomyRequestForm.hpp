#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
    private:
        std::string m_target;
        RobotomyRequestForm();
    public:
        RobotomyRequestForm(const std::string& m_target);
        RobotomyRequestForm(const RobotomyRequestForm& f);
        RobotomyRequestForm& operator=(const RobotomyRequestForm&  f);
        ~RobotomyRequestForm();

        std::string getTarget() const;

        void execute(const Bureaucrat& b) const;
};

#endif