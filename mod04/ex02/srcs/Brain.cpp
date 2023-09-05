#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain: Default constructor called\n";
}

Brain::Brain(Brain &other)
{
	std::cout << "Brain: Copy constructor called\n";
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
}

Brain::~Brain()
{
	std::cout << "Brain: Destructor called\n";
}

Brain &Brain::operator=(Brain &other)
{
	std::cout << "Brain: = operator called\n";
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
	return *this;
}
