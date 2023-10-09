#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <ctime>

void print_time(clock_t start_time, clock_t end_time,
				int container_len, const std::string &container_name)
{
	double elapsed_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000;
	std::cout << "Time to process a range of " << container_len
			  << " elements with " << container_name << " : "
			  << elapsed_time << " ms\n";
}

int main(int ac, char **av)
{
	// check
	if (!PmergeMe<std::vector<long> >::checkArgs(--ac, ++av))
		(std::cout << "Error\n", exit(1));
	// print before
	std::cout << "Before:";
	PmergeMe<std::vector<long> > sorterVector;
	for (int i = 0; i < ac; i++)
		std::cout << ' ' << av[i];
	std::cout << '\n';
	// use std::vector
	clock_t start_time = clock();
	sorterVector.sort(ac, av);
	clock_t end_time = clock();
	// print after
	std::cout << "After:  ";
	sorterVector.print();
	// print std::vector's time
	print_time(start_time, end_time, ac, "std::vector");
	PmergeMe<std::deque<long> > sorterDeque;
	start_time = clock();
	sorterDeque.sort(ac, av);
	end_time = clock();
	print_time(start_time, end_time, ac, "std::deque ");
}
