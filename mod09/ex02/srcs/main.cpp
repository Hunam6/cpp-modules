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
}
