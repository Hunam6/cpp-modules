#include "Fixed.hpp"
#include <iostream>

int main(void)
{
	Fixed a;
	a.setRawBits(0b10101010);
	Fixed b(a);
	Fixed c;

	c = b;
	c.setRawBits(0b01010101);

	std::cout << a.getRawBits() << '\n';
	std::cout << b.getRawBits() << '\n';
	std::cout << c.getRawBits() << '\n';

	return 0;
}
