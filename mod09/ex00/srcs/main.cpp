#include <iostream>
#include <fstream>
#include <map>
#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		(std::cerr << "Error: could not open file.\n", exit(1));
	std::ifstream input(av[1]);
	if (!input)
		(std::cerr << "Error: could not open file.\n", exit(1));
	BitcoinExchange exchange;

	std::string line;
	std::getline(input, line);
	if (line != "date | value")
		(std::cerr << "Error: no valid header\n", exit(1));
	while (42)
	{
		std::getline(input, line);
		if (input.eof())
		{
			if (!line.empty())
				std::cerr << "Error: no ending newline\n";
			break;
		}
		exchange.search(line);
	}
}
