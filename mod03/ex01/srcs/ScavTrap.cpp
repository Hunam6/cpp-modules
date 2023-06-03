#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap: Default constructor called\n";
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
}

ScavTrap::ScavTrap(const std::string newName) : ClapTrap(newName)
{
	std::cout << "ScavTrap: Name constructor called\n";
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap: Copy constructor called\n";
	setName(other.getName());
	setHitPoints(other.getHitPoints());
	setEnergyPoints(other.getEnergyPoints());
	setAttackDamage(other.getAttackDamage());
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap: Destructor called\n";
}

ScavTrap &ScavTrap::operator=(ScavTrap &other)
{
	setName(other.getName());
	setHitPoints(other.getHitPoints());
	setEnergyPoints(other.getEnergyPoints());
	setAttackDamage(other.getAttackDamage());
	return *this;
}

void ScavTrap::attack(const std::string &target)
{
	if (getHitPoints() == 0 || getEnergyPoints() == 0)
		return;
	std::cout << "ScavTrap: " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!\n";
	setEnergyPoints(getEnergyPoints() - 1);
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap: is now in Gate keeper mode.\n";
}
