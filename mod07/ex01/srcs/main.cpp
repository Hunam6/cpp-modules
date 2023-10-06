#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void print(T const &x)
{
	std::cout << x << std::endl;
	return;
}

int main()
{
	int tab[] = {0, 1, 2, 3, 4, 5};
	iter(tab, 6, print);

	std::string tab2[] = {"first", "second"};
	iter(tab2, 2, print);
}
