#include "PmergeMe.hpp"
#include <algorithm>
#include <iostream>

template <typename Container>
void PmergeMe<Container>::insertionSort(Container &arr, int start, int end)
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

template <typename Container>
void PmergeMe<Container>::merge(Container &arr, int left, int middle, int right)
{
	int left_size = middle - left + 1;
	int right_size = right - middle;

	Container left_arr(arr.begin() + left, arr.begin() + middle + 1);
	Container right_arr(arr.begin() + middle + 1, arr.begin() + right + 1);

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

template <typename Container>
void PmergeMe<Container>::mergeSort(Container &arr, int start, int end)
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

template <typename Container>
void PmergeMe<Container>::sort()
{
	mergeSort(container, 0, container.size() - 1);
}
