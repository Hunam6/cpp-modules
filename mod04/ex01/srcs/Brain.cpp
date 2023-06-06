#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain: Default constructor called\n";
}

Brain::Brain(Brain &other)
{
	std::cout << "Brain: Copy constructor called\n";
	std::copy(other.ideas->begin(), other.ideas->end(), ideas->begin());
}

Brain::~Brain()
{
	std::cout << "Brain: Destructor called\n";
}

Brain &Brain::operator=(Brain &other)
{
	std::cout << "Brain: = operator called\n";
	std::copy(other.ideas->begin(), other.ideas->end(), ideas->begin());
	return *this;
}
