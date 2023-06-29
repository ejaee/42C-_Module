#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <stack>

class RPN
{
	private:
		std::stack<double> stack;

		RPN();
		RPN(const RPN &copy);
		RPN & operator=(const RPN &assign);

        void    validateValue(const char value);
		void    calc(const std::string& input);
		void	calcTo(char op);

	public:
		RPN(const std::string& input);
		~RPN();

        void    run();

		class WrongToken : public std::exception {
			virtual const char* what() const throw();
		};
		class DividedZero : public std::exception {
			virtual const char* what() const throw();
		};
};

#endif