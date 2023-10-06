#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main()
{
	std::vector<int> arr;
	arr.push_back(3);
	arr.push_back(42);
	arr.push_back(7);
	arr.push_back(23);
	arr.push_back(9);

	std::cout << easyfind(arr, 42) << '\n';
	// std::cout << easyfind(arr, -3) << '\n'; // will throw
}
