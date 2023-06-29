#include "RPN.hpp"

void	RPN::validateValue(const char value) {
	if (value < '0' || '9' < value)
		throw WrongToken();
}

void	RPN::run() {
	if (stack.size() == 1)
		std::cout << stack.top() << std::endl;
}

RPN::RPN(const std::string& input)
{
	try {
		calc(input);
	} catch(const std::exception& e)
    {
        std::cerr << "Error" << std::endl;
    }
}

RPN::~RPN() {}

void	RPN::calcTo(char op) {
	if (stack.size() < 2)
		throw WrongToken();

	double a = stack.top();
	stack.pop();
	double b = stack.top();
	stack.pop();

	if (op == '+')
		stack.push(b + a);
	else if (op == '-')
		stack.push(b - a);
	else if (op == '*')
		stack.push(b * a);
	else if (op == '/')
		stack.push(b / a);
	else
		throw WrongToken();
}

void	RPN::calc(const std::string& input)
{
	std::stringstream stream(input);
	char value;

	stream >> value;
	if (stream.fail())
		throw WrongToken();
	validateValue(value);
	stack.push(value - '0');
	while (stream >> value)
	{
		if (stream.fail())
			throw WrongToken();
		if ('0' <= value && value <= '9')
			stack.push(value - '0');
		else
			calcTo(value);
	}
	if (stack.size() != 1)
		throw WrongToken();
}

const char * RPN::WrongToken::what() const throw()
{
	return "Error";
}

const char *RPN::DividedZero::what() const throw()
{
    return "Error";
}
