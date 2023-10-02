#include <iostream>
#include "Span.hpp"

int main()
{
	// small span
	Span small_sp = Span(6);
	small_sp.addNumber(6);
	small_sp.addNumber(3);
	small_sp.addNumber(17);
	small_sp.addNumber(9);
	small_sp.addNumber(11);
	std::cout << small_sp.shortestSpan() << std::endl;
	std::cout << small_sp.longestSpan() << std::endl;

	// long span
	std::array<int, 20000> lots_of_numbers;
	std::srand(std::time(NULL));
	for (size_t i = 0; i < lots_of_numbers.size(); ++i)
		lots_of_numbers[i] = std::rand();

	Span long_sp(20000);
	// long_sp.addNumber(1); // will throw
	long_sp.addNumber(lots_of_numbers.begin(), lots_of_numbers.end());
	std::cout << long_sp.shortestSpan() << std::endl;
	std::cout << long_sp.longestSpan() << std::endl;

	// copy testing
	Span copy_sp(small_sp);
	std::cout << "Equal: " << copy_sp.longestSpan() << std::endl;
	small_sp.addNumber(20000);
	std::cout << "Equal: " << copy_sp.longestSpan() << std::endl;
	Span sec_copy_sp(5);
	sec_copy_sp = copy_sp;
	std::cout << "Equal: " << sec_copy_sp.longestSpan() << std::endl;
}
