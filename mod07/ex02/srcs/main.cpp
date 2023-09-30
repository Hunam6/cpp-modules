#include <iostream>
#include "Array.hpp"

int main()
{
	Array<std::string> string_arr(2);

	string_arr[1] = "hey";
	string_arr[0] = "hey";
	// string_arr[2] = std::string("hey"); // will out of bounds
	std::cout << string_arr[0] << '\n';

	Array<std::string> sec_arr(string_arr);
	sec_arr[0] = "hello";
	std::cout << string_arr[0] << '\n';
	std::cout << sec_arr[0] << '\n';

	Array<std::string> bigger_arr(10);
	bigger_arr = string_arr;
	bigger_arr[0] = "bonjour";
	std::cout << string_arr[0] << '\n';
	std::cout << bigger_arr[0] << '\n';
	std::cout << bigger_arr.size() << '\n';
}
