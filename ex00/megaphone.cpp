#include <iostream>

int main(int ac, char **av) {
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return 0;
	}
	for (int i = 1; i < ac; i++)
	{
		std::string str = av[i];
		std::transform(str.begin(), str.end(), str.begin(), ::toupper);
		std::cout << str;
	}
	std::cout << "\n";
}

