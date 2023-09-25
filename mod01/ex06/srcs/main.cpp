#include "Harl.hpp"
#include <iostream>

int main(int ac, char **av)
{
	std::string input;
	if (ac == 2)
		input = av[1];
	if (ac != 2 || !(input == "DEBUG" || input == "INFO" || input == "WARNING" || input == "ERROR"))
	{
		std::cout << "[ Probably complaining about insignificant problems ]\n";
		return 0;
	}

	Harl harl;
	switch (input[0])
	{
	case 'D':
		harl.complain("DEBUG");
	case 'I':
		harl.complain("INFO");
	case 'W':
		harl.complain("WARNING");
	default:
		harl.complain("ERROR");
	}
}
