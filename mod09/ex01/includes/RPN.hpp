#pragma once
#ifndef RPN_HPP
#define RPN_HPP
#include <string>
#include <stack>

class RPN
{
private:
	std::stack<double> stack;

	double evaluate(double first, char op, double second);
	void emptyStack();

public:
	RPN();
	RPN(const RPN &other);
	~RPN();

	RPN &operator=(const RPN &other);

	void interpret(const std::string &expr);
};

#endif
