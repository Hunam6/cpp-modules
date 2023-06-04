#pragma once
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
private:
	std::string name;
	int hitPoints;
	int energyPoints;
	int attackDamage;

protected:
	std::string getName() const;
	void setName(const std::string newName);
	int getHitPoints() const;
	void setHitPoints(const int newHitPoints);
	int getEnergyPoints() const;
	void setEnergyPoints(const int newEnergyPoints);
	int getAttackDamage() const;
	void setAttackDamage(const int newAttackDamage);

public:
	ClapTrap();
	ClapTrap(const std::string newName);
	ClapTrap(const ClapTrap &other);
	~ClapTrap();

	ClapTrap &operator=(ClapTrap &other);

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif
