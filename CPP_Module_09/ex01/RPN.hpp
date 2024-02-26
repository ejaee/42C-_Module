#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <stack>

# define ADDITION '+'
# define SUBTRACTION '-'
# define DIVISION '*'
# define MULTIPLICATION '/'

# define ERROR_MESSAGE "Error"

class RPN
{
	private:
		std::stack<double> stack;

		RPN();
		RPN(const RPN &copy);
		RPN & operator=(const RPN &assign);

        void    validateValue(const char value);
		void    run(const std::string& input);
		void	calculate(char op);

	public:
		RPN(const std::string& input);
		~RPN();

        void    printAnswer();

		class WrongToken : public std::exception {
			virtual const char* what() const throw();
		};
		class DividedZero : public std::exception {
			virtual const char* what() const throw();
		};
};

#endif