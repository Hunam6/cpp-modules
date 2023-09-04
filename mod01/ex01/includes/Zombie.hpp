#pragma once
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
private:
	std::string name;

public:
	Zombie() {}
	~Zombie() {}
	void announce();
	void setName(std::string name);
};

#endif
