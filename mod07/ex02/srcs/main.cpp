#include <iostream>
#include "Array.hpp"

int main()
{
	Array<float> empty1;
	Array<float> empty2(0);
	// (void)empty1[0]; // will out of bounds

	Array<std::string> string_arr(2);

	string_arr[1] = "hey";
	string_arr[0] = "hey";
	// string_arr[2] = std::string("hey"); // will out of bounds
	std::cout << string_arr[0] << '\n';

	Array<std::string> sec_arr(string_arr);
	sec_arr[0] = "hello";
	std::cout << string_arr[0] << '\n';
	std::cout << sec_arr[0] << '\n';

	Array<std::string> bigger_arr(10); // if this is const
	bigger_arr = string_arr;
	bigger_arr[0] = "bonjour"; // this will not compile
	std::cout << string_arr[0] << '\n';
	std::cout << bigger_arr[0] << '\n';
	std::cout << bigger_arr.size() << '\n';
}
