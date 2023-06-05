#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap: Default constructor called\n";
	ClapTrap::setName("_clap_name");
	ClapTrap::setHitPoints(FragTrap::getHitPoints());
	ClapTrap::setEnergyPoints(ScavTrap::getEnergyPoints());
	ClapTrap::setAttackDamage(FragTrap::getAttackDamage());
}

DiamondTrap::DiamondTrap(const std::string newName)
{
	std::cout << "DiamondTrap: Name constructor called\n";
	name = newName;
	ClapTrap::setName(newName + "_clap_name");
	ClapTrap::setHitPoints(FragTrap::getHitPoints());
	ClapTrap::setEnergyPoints(ScavTrap::getEnergyPoints());
	ClapTrap::setAttackDamage(FragTrap::getAttackDamage());
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
{
	std::cout << "DiamondTrap: Copy constructor called\n";
	name = other.name;
	ClapTrap::setName(other.name + "_clap_name");
	ClapTrap::setHitPoints(other.FragTrap::getHitPoints());
	ClapTrap::setEnergyPoints(other.ScavTrap::getEnergyPoints());
	ClapTrap::setAttackDamage(other.FragTrap::getAttackDamage());
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap: Destructor called\n";
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap &other)
{
	name = other.name;
	ClapTrap::setName(other.name + "_clap_name");
	ClapTrap::setHitPoints(other.FragTrap::getHitPoints());
	ClapTrap::setEnergyPoints(other.ScavTrap::getEnergyPoints());
	ClapTrap::setAttackDamage(other.FragTrap::getAttackDamage());
	return *this;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap: " << name << " ClapTrap.name: " << ScavTrap::getName() << "\n";
}
