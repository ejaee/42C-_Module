#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "AForm.hpp"

# define RED    "\033[0;31m"
# define GREEN  "\033[1;32m"
# define YELLOW "\033[0;33m"
# define BLUE   "\033[0;34m"
# define RESET  "\033[0m"

class AForm;

class Bureaucrat {
    private:
        const std::string m_name;
        int m_grade;
        
        Bureaucrat();
    public:
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat& b);
        Bureaucrat& operator=(const Bureaucrat& b);
        ~Bureaucrat();

        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };

        const std::string& getName() const;
        const int& getGrade() const;
        
        void    increaseGrade();
        void    decreaseGrade();
        void    signForm(AForm& f) const;
        void    executeForm(const AForm& f) const;

};

std::ostream& operator<<(std::ostream& ofs, const Bureaucrat& b);

# endif