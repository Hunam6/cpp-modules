#pragma once
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

template <typename Container>
class PmergeMe
{
private:
	static const int GROUP_SIZE = 5;
	Container container;

	static bool isValidValue(const char *str);

	void insertionSort(Container &arr, int start, int end);
	void merge(Container &arr, int start, int middle, int end);
	void mergeSort(Container &arr, int start, int last);

public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	~PmergeMe();

	PmergeMe &operator=(const PmergeMe &other);

	static bool checkArgs(int len, char **args);
	void sort(int len, char **args);
	void print();
};

#include "../srcs/PmergeMe.tpp"
#include "../srcs/mergeInsertSort.tpp"

#endif
