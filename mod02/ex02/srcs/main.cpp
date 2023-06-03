#include "Fixed.hpp"
#include <iostream>

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) / Fixed(2)); // 10.1

	std::cout << a << std::endl;   // 0
	std::cout << ++a << std::endl; // 0.01
	std::cout << a << std::endl;   // 0.01
	std::cout << a++ << std::endl; // 0.01
	std::cout << a << std::endl;   // 0.02

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;
}
