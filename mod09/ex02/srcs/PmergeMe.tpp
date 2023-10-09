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
void PmergeMe<Container>::inputArgs(int len, char **args)
{
	for (int i = 0; i < len; i++)
	{
		long num;
		if (!isValidValue(args[i], &num))
			(std::cout << "Error\n", exit(1));
		// don't add duplicates
		if (std::find(container.begin(), container.end(), num) == container.end())
			container.push_back(num);
	}
}
