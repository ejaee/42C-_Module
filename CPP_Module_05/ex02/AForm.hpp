#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private:
        const std::string   m_name;
        bool                m_signStatus;
        const int           m_signGrade;
        const int           m_execGrade;

    public:
        AForm();
        AForm(const std::string& name, const int& signGrade, const int& execGrade);
        AForm(const AForm& form);
        AForm& operator=(const AForm& f);
        virtual ~AForm();

        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };

        class NotSignedException : public std::exception {
            public:
                const char* what() const throw();
        };

        class NoPermissionException : public std::exception {
            public:
                const char* what() const throw();
        };

        class FileException : public std::exception {
            public:
                const char* what() const throw();
        };

        const std::string&  getName() const;
        const bool&         getSignStatus() const;
        const int&          getSignGrade() const;
        const int&          getExecGrade() const;

        void                beSigned(const Bureaucrat& b);
        void                checkExecutable(const Bureaucrat& b) const;
        virtual void        execute(const Bureaucrat& b) const = 0;
};

std::ostream& operator<<(std::ostream& ofs, const AForm& f);

#endif
