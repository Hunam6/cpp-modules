#pragma once
#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <vector>
#include <deque>

template <typename Container>
class PmergeMe
{
private:
	static const int GROUP_SIZE = 5;

	bool isValidValue(const std::string &str, long *result);
	void insertionSort(Container &arr, int start, int end);
	void merge(Container &arr, int start, int middle, int end);

public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	~PmergeMe();

	PmergeMe &operator=(const PmergeMe &other);

	std::vector<long> argsToVector(int len, char **args);
	std::deque<long> argsToDeque(int len, char **args);
	void mergeSort(Container &arr, int start, int last);
};

#include "../srcs/PmergeMe.tpp"
#include "../srcs/mergeInsertSort.tpp"

#endif
