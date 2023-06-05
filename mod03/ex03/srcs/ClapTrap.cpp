#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
	: hitPoints(10),
	  energyPoints(10),
	  attackDamage(0)
{
	std::cout << "ClapTrap: Default constructor called\n";
}

ClapTrap::ClapTrap(const std::string newName)
	: name(newName),
	  hitPoints(10),
	  energyPoints(10),
	  attackDamage(0)
{
	std::cout << "ClapTrap: Name constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap &other)
	: name(other.name),
	  hitPoints(other.hitPoints),
	  energyPoints(other.energyPoints),
	  attackDamage(other.attackDamage)
{
	std::cout << "ClapTrap: Copy constructor called\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap: Destructor called\n";
}

ClapTrap &ClapTrap::operator=(ClapTrap &other)
{
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	return *this;
}

void ClapTrap::attack(const std::string &target)
{
	if (hitPoints == 0 || energyPoints == 0)
		return;
	std::cout << "ClapTrap: " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!\n";
	energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints == 0)
		return;
	std::cout << "ClapTrap: " << name << " took " << amount << " points of damage!\n";
	hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints == 0)
		return;
	std::cout << "ClapTrap: " << name << " is repairing by " << amount << " points of damage!\n";
	hitPoints += amount;
	energyPoints--;
}

std::string ClapTrap::getName() const
{
	return name;
}

void ClapTrap::setName(const std::string newName)
{
	name = newName;
}

int ClapTrap::getHitPoints() const
{
	return hitPoints;
}

void ClapTrap::setHitPoints(const int newHitPoints)
{
	hitPoints = newHitPoints;
}

int ClapTrap::getEnergyPoints() const
{
	return energyPoints;
}

void ClapTrap::setEnergyPoints(const int newEnergyPoints)
{
	energyPoints = newEnergyPoints;
}

int ClapTrap::getAttackDamage() const
{
	return attackDamage;
}

void ClapTrap::setAttackDamage(const int newAttackDamage)
{
	attackDamage = newAttackDamage;
}
