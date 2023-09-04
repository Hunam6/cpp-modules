#pragma once
#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
	std::string name;

public:
	DiamondTrap();
	DiamondTrap(const std::string name);
	DiamondTrap(const DiamondTrap &other);
	~DiamondTrap();

	DiamondTrap &operator=(DiamondTrap &other);

	void attack(const std::string &target);
	void whoAmI();
};

#endif
