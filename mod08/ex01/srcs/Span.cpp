#include "Span.hpp"
#include <algorithm>

Span::Span()
	: max_length(0) {}

Span::Span(unsigned int N)
	: max_length(N) {}

Span::Span(const Span &other)
	: numbers(other.numbers), max_length(other.max_length) {}

Span::~Span() {}

Span &Span::operator=(const Span &other)
{
	max_length = other.max_length;
	numbers.resize(other.numbers.size());
	std::copy(other.numbers.begin(), other.numbers.end(), numbers.begin());
	return *this;
}

void Span::addNumber(int number)
{
	if (numbers.size() + 1 > max_length)
		throw std::out_of_range("Span::addNumber");
	numbers.push_back(number);
	std::sort(numbers.begin(), numbers.end());
}

int Span::shortestSpan()
{
	if (numbers.size() <= 1)
		throw std::runtime_error("no span can be found");

	int min = INT_MAX;
	for (unsigned int i = 1; i < numbers.size(); i++)
		min = std::min(min, numbers[i] - numbers[i - 1]);
	return min;
}
int Span::longestSpan()
{
	if (numbers.size() <= 1)
		throw std::runtime_error("no span can be found");
	return numbers.back() - numbers.front();
}
