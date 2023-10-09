#include "PmergeMe.hpp"
#include <iostream>

int main(int ac, char **av)
{
	PmergeMe sorter;

	std::vector<long> vector = sorter.argsToVector(ac - 1, ++av);
	sorter.mergeSort(vector, 0, vector.size() - 1);
	for (size_t i = 0; i < vector.size(); i++)
		std::cout << vector[i] << " ";
	std::cout << std::endl;

	std::deque<long> deque = sorter.argsToDeque(ac - 1, av);
	sorter.mergeSort(deque, 0, deque.size() - 1);
	for (size_t i = 0; i < deque.size(); i++)
		std::cout << deque[i] << " ";
	std::cout << std::endl;
}
