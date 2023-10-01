#include <iostream>
#include <array>
#include "easyfind.hpp"

int main()
{
	std::array<int, 5> arr = {3, 42, 7, 23, 9};

	std::cout << easyfind(arr, 42) << '\n';
	// std::cout << easyfind(arr, -3) << '\n'; // will throw
}
