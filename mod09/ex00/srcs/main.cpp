#include <iostream>
#include <map>
#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	// std::map<std::string, float> map;
	// map["abc"] = 1;
	// map["44"] = 2;
	// map["QQ"] = 3;
	// map["))))"] = 4;
	// std::cout << map.count("QQ") << '\n';
	// std::cout << map.count("Q") << '\n';
	// std::map<std::string, float>::iterator it = map.lower_bound("QQ");
	// std::cout << (*it).first << '\n';
	// it--;
	// std::cout << (*it).first << '\n';

	if (ac != 2)
		return (std::cout << "Usage: ./btc <input.txt>\n", 0);
	BitcoinExchange exchange;
	(void)av;
}
