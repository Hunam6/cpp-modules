#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		return 0;
	RPN rpn;
	rpn.interpret(av[1]);
}
