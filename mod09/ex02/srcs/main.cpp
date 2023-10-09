#include "PmergeMe.hpp"
#include <iostream>
#include <vector>

int main(int ac, char **av)
{
	PmergeMe<std::vector<long> > sorterVector;
	std::vector<long> vector = sorterVector.argsToVector(ac - 1, ++av);
	sorterVector.mergeSort(vector, 0, vector.size() - 1);
	for (size_t i = 0; i < vector.size(); i++)
		std::cout << vector[i] << " ";
	std::cout << std::endl;

	PmergeMe<std::deque<long> > sorterDeque;
	std::deque<long> deque = sorterDeque.argsToDeque(ac - 1, av);
	sorterDeque.mergeSort(deque, 0, deque.size() - 1);
	for (size_t i = 0; i < deque.size(); i++)
		std::cout << deque[i] << " ";
	std::cout << std::endl;
}
