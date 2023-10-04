#pragma once
#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
private:
	std::string ideas[100];
	int ideas_len;

public:
	Brain();
	Brain(Brain &other);
	~Brain();

	Brain &operator=(Brain &other);

	void addIdea(std::string idea);
	std::string getIdea(int idx);
};

#endif
