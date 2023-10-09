#pragma once
#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <string>

template <typename Container>
class PmergeMe
{
private:
	static const int GROUP_SIZE = 5;

	bool isValidValue(const std::string &str, long *result);
	void insertionSort(Container &arr, int start, int end);
	void merge(Container &arr, int start, int middle, int end);
	void mergeSort(Container &arr, int start, int last);

public:
	Container container;

	PmergeMe();
	PmergeMe(const PmergeMe &other);
	~PmergeMe();

	PmergeMe &operator=(const PmergeMe &other);

	void inputArgs(int len, char **args);
	void sort();
};

#include "../srcs/PmergeMe.tpp"
#include "../srcs/mergeInsertSort.tpp"

#endif
