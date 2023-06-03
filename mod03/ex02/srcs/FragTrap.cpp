#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap: Default constructor called\n";
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
}

FragTrap::FragTrap(const std::string newName) : ClapTrap(newName)
{
	std::cout << "FragTrap: Name constructor called\n";
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap: Copy constructor called\n";
	setName(other.getName());
	setHitPoints(other.getHitPoints());
	setEnergyPoints(other.getEnergyPoints());
	setAttackDamage(other.getAttackDamage());
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap: Destructor called\n";
}

FragTrap &FragTrap::operator=(FragTrap &other)
{
	setName(other.getName());
	setHitPoints(other.getHitPoints());
	setEnergyPoints(other.getEnergyPoints());
	setAttackDamage(other.getAttackDamage());
	return *this;
}

void FragTrap::attack(const std::string &target)
{
	if (getHitPoints() == 0 || getEnergyPoints() == 0)
		return;
	std::cout << "FragTrap: " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!\n";
	setEnergyPoints(getEnergyPoints() - 1);
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap: is making a high fives request.\n";
}
