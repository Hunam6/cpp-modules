#include "Brain.hpp"
#include <iostream>

Brain::Brain()
	: ideas_len(0)
{
	std::cout << "Brain: Default constructor called\n";
}

Brain::Brain(Brain &other)
	: ideas_len(other.ideas_len)
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
	ideas_len = other.ideas_len;
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
	return *this;
}

void Brain::addIdea(std::string idea)
{
	if (ideas_len < 100)
		ideas[ideas_len++] = idea;
}

std::string Brain::getIdea(int idx)
{
	if (idx < ideas_len)
		return ideas[idx];
	return "";
}
