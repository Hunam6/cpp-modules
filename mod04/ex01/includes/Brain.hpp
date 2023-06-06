#pragma once
#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
public:
	std::string ideas[100];

	Brain();
	Brain(Brain &other);
	~Brain();

	Brain &operator=(Brain &other);
};

#endif
