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
bool PmergeMe<Container>::isValidValue(const char *str)
{
	char *endptr;
	long result = std::strtol(str, &endptr, 10);

	return !(endptr == str || *endptr != '\0' || result < 0 || (result == LONG_MAX && errno == ERANGE));
}

template <typename Container>
void PmergeMe<Container>::print()
{
	for (size_t i = 0; i < container.size(); i++)
		std::cout << container[i] << " ";
	std::cout << '\n';
	container.clear();
}

template <typename Container>
bool PmergeMe<Container>::checkArgs(int len, char **args)
{
	for (int i = 0; i < len; i++)
		if (!isValidValue(args[i]))
			return false;
	return true;
}

template <typename Container>
void PmergeMe<Container>::sort(int len, char **args)
{
	for (int i = 0; i < len; i++)
		container.push_back(strtol(args[i], NULL, 10));
	mergeSort(container, 0, container.size() - 1);
}
