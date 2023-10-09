#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>

int main(int ac, char **av)
{
	PmergeMe<std::vector<long> > sorterVector;
	sorterVector.inputArgs(ac - 1, ++av);
	sorterVector.sort();
	for (size_t i = 0; i < sorterVector.container.size(); i++)
		std::cout << sorterVector.container[i] << " ";
	std::cout << std::endl;

	PmergeMe<std::deque<long> > sorterDeque;
	sorterDeque.inputArgs(ac - 1, av);
	sorterDeque.sort();
	for (size_t i = 0; i < sorterDeque.container.size(); i++)
		std::cout << sorterDeque.container[i] << " ";
	std::cout << std::endl;
}
