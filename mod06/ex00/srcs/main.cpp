#include <iostream>
#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		(std::cout << "Usage: ./convert <literal>\n", exit(0));
	ScalarConverter::convert(av[1]);
}
