#include "Harl.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "Usage:\n\tharlFilter <level>\n";
		return 1;
	}
	std::string input = av[1];
	if ((input != "DEBUG" && input != "INFO" && input != "WARNING" && input != "ERROR"))
	{
		std::cout << "[ Probably complaining about insignificant problems ]\n";
		return 0;
	}
	Harl harl(input);

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
}
