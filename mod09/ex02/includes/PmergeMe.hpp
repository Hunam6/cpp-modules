#pragma once
#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <vector>

class PmergeMe
{
private:
	static const int GROUP_SIZE = 5;
	bool isValidValue(const std::string &str, long *result);
	void insertionSort(std::vector<long> &arr, int start, int end);
	void merge(std::vector<long> &arr, int start, int middle, int end);

public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	~PmergeMe();

	PmergeMe &operator=(const PmergeMe &other);

	void mergeSort(std::vector<long> &arr, int start, int last);
	std::vector<long> argsToVector(int len, char **args);
};

#endif
