#include "PmergeMe.hpp"
#include <string>
#include <algorithm>
#include <iostream>

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

std::vector<long> PmergeMe::argsToVector(int len, char **args)
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

void PmergeMe::insertionSort(std::vector<long> &arr, int start, int end)
{
	for (int i = start; i < end; i++)
	{
		long temp_val = arr[i + 1];
		int j = i + 1;
		while (j > start && arr[j - 1] > temp_val)
		{
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = temp_val;
	}
}

void PmergeMe::merge(std::vector<long> &arr, int left, int middle, int right)
{
	int left_size = middle - left + 1;
	int right_size = right - middle;

	std::vector<long> left_arr(arr.begin() + left, arr.begin() + middle + 1);
	std::vector<long> right_arr(arr.begin() + middle + 1, arr.begin() + right + 1);

	int left_idx = 0;
	int right_idx = 0;

	for (int i = left; i <= right; i++)
	{
		if (right_idx == right_size)
			arr[i] = left_arr[left_idx++];
		else if (left_idx == left_size)
			arr[i] = right_arr[right_idx++];
		else if (right_arr[right_idx] > left_arr[left_idx])
			arr[i] = left_arr[left_idx++];
		else
			arr[i] = right_arr[right_idx++];
	}
}

void PmergeMe::mergeSort(std::vector<long> &arr, int start, int end)
{
	if (end - start > GROUP_SIZE)
	{
		int middle = (start + end) / 2;
		mergeSort(arr, start, middle);
		mergeSort(arr, middle + 1, end);
		merge(arr, start, middle, end);
	}
	else
		insertionSort(arr, start, end);
}
