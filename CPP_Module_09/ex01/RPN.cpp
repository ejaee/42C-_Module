#include "RPN.hpp"

RPN::RPN(const std::string& input)
{
	try {
		run(input);
	} catch(const std::exception& e)
    {
        std::cerr << ERROR_MESSAGE << std::endl;
    }
}

RPN::~RPN() {}

/**************************************************/

void	RPN::run(const std::string& input)
{
	std::stringstream stream(input);
	char value;

	stream >> value;
	if (stream.fail()) throw WrongToken();

	validateValue(value);
	stack.push(value - '0');
	while (stream >> value)
	{
		if (stream.fail())
			throw WrongToken();
		if ('0' <= value && value <= '9')
			stack.push(value - '0');
		else
			calculate(value);
	}
	if (stack.size() != 1)
		throw WrongToken();
}


void	RPN::validateValue(const char value) {
	if (value < '0' || '9' < value)
		throw WrongToken();
}

void	RPN::calculate(char op) {
	if (stack.size() < 2)
		throw WrongToken();

	double a = stack.top();
	stack.pop();
	double b = stack.top();
	stack.pop();

	if (op == ADDITION)
		stack.push(b + a);
	else if (op == SUBTRACTION)
		stack.push(b - a);
	else if (op == DIVISION)
		stack.push(b * a);
	else if (op == MULTIPLICATION)
		stack.push(b / a);
	else
		throw WrongToken();
}

void	RPN::printAnswer() {
	if (stack.size() == 1)
		std::cout << stack.top() << std::endl;
}

const char * RPN::WrongToken::what() const throw()
{
	return ERROR_MESSAGE;
}

const char *RPN::DividedZero::what() const throw()
{
    return ERROR_MESSAGE;
}
