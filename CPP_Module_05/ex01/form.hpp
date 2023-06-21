#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Form {
    private:
        const std::string   m_name;
        bool                m_beSigned;
        const int           m_signGrade;
        const int           m_execGrade;

    public:
        Form();
        Form(const std::string& name, const int& signGrade, const int& execGrade);
        Form(const Form& form);
        Form& operator=(const Form& f);
        ~Form();

        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };

        const std::string&  getName() const;
        const bool&         getBeSigned() const;
        const int&          getSignGrade() const;
        const int&          getExecGrade() const;

        void                beSigned(const Bureaucrat& b);
};

std::ostream& operator<<(std::ostream& ofs, const Form& f);

#endif
