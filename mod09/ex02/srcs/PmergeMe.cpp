#include "PmergeMe.hpp"
#include <string>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
	// TODO
}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	(void)other;
	// TODO
	return *this;
}

bool PmergeMe::isValidValue(const std::string &str, long *result)
{
	char *endptr;
	*result = strtol(str.c_str(), &endptr, 10);

	if (endptr == str.c_str() || *endptr != '\0' || *result < 0)
		return false;
	return true;
}
