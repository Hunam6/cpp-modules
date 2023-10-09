#include "RPN.hpp"
#include <iostream>
#include <sstream>

RPN::RPN() {}

RPN::RPN(const RPN &other) { (void)other; }

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &other)
{
	(void)other;
	return *this;
}

double RPN::evaluate(double first, char op, double second)
{
	switch (op)
	{
	case '+':
		return first + second;
	case '-':
		return first - second;
	case '*':
		return first * second;
	default:
		return first / second;
	}
}

void RPN::emptyStack()
{
	while (!stack.empty())
		stack.pop();
}

void RPN::interpret(const std::string &expr)
{
	std::stringstream ss(expr);

	while (!ss.eof())
	{
		// get operator or digit
		char ch;
		ss.get(ch);
		if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
		{
			// calculate
			if (stack.size() < 2)
				return (std::cerr << "Error\n", emptyStack());
			double second = stack.top();
			stack.pop();
			double first = stack.top();
			stack.pop();
			stack.push(evaluate(first, ch, second));
		}
		else if ('0' <= ch && ch <= '9')
			stack.push(ch - '0');
		// check formatting
		if (stack.empty())
			return (std::cerr << "Error\n", emptyStack());
		if ((!ss.get(ch) && ch != ' ') || (ch == ' ' && !ss.eof()))
			continue;
		return (std::cerr << "Error\n", emptyStack());
	}
	while (stack.size() != 1)
		stack.pop();
	std::cout << stack.top() << '\n';
	emptyStack();
}
