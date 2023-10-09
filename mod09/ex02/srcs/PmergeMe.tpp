#include "PmergeMe.hpp"
#include <string>
#include <iostream>

template <typename Container>
PmergeMe<Container>::PmergeMe() {}

template <typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe &other)
{
	(void)other;
}

template <typename Container>
PmergeMe<Container>::~PmergeMe() {}

template <typename Container>
PmergeMe<Container> &PmergeMe<Container>::operator=(const PmergeMe &other)
{
	(void)other;
	return *this;
}

template <typename Container>
bool PmergeMe<Container>::isValidValue(const std::string &str, long *result)
{
	char *endptr;
	*result = strtol(str.c_str(), &endptr, 10);

	if (endptr == str.c_str() || *endptr != '\0' || *result < 0)
		return false;
	return true;
}

template <typename Container>
std::vector<long> PmergeMe<Container>::argsToVector(int len, char **args)
{
	std::vector<long> out;

	for (int i = 0; i < len; i++)
	{
		long num;
		if (!isValidValue(args[i], &num))
			(std::cout << "Error\n", exit(1));
		// don't add duplicates
		if (std::find(out.begin(), out.end(), num) == out.end())
			out.push_back(num);
	}
	return out;
}

template <typename Container>
std::deque<long> PmergeMe<Container>::argsToDeque(int len, char **args)
{
	std::deque<long> out;

	for (int i = 0; i < len; i++)
	{
		long num;
		if (!isValidValue(args[i], &num))
			(std::cout << "Error\n", exit(1));
		// don't add duplicates
		if (std::find(out.begin(), out.end(), num) == out.end())
			out.push_back(num);
	}
	return out;
}
