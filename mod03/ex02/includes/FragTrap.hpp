#pragma once
#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap();
	FragTrap(const std::string name);
	FragTrap(const FragTrap &other);
	~FragTrap();

	FragTrap &operator=(FragTrap &other);

	void attack(const std::string &target);
	void highFivesGuys();
};

#endif
