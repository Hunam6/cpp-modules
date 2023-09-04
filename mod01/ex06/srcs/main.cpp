#include "Harl.hpp"
#include <iostream>

int main(int ac, char **av)
{
	std::string input;
	if (ac == 2)
		input = av[1];
	int levelThreshold = -1;
	Harl harl;

	if (input == "DEBUG")
		levelThreshold = 0;
	else if (input == "INFO")
		levelThreshold = 1;
	else if (input == "WARNING")
		levelThreshold = 2;
	else if (input == "ERROR")
		levelThreshold = 3;

	switch (levelThreshold)
	{
	case 0:
		harl.complain("DEBUG");
	case 1:
		harl.complain("INFO");
	case 2:
		harl.complain("WARNING");
	case 3:
		harl.complain("ERROR");
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}
