#pragma once
#ifndef SPAN_HPP
#define SPAN_HPP
#include <vector>

class Span
{
private:
	std::vector<int> numbers;
	unsigned int max_length;

public:
	Span();
	Span(unsigned int N);
	Span(const Span &other);
	~Span();

	Span &operator=(const Span &other);

	void addNumber(int number);

	template <typename InputIterator>
	void addNumber(InputIterator first, InputIterator last)
	{
		if (numbers.size() + std::distance(first, last) > max_length)
			throw std::out_of_range("Span::addNumber");
		numbers.insert(numbers.end(), first, last);
		std::sort(numbers.begin(), numbers.end());
	}

	int shortestSpan();
	int longestSpan();
};

#endif
