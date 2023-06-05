#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	FragTrap::setName("_clap_name");
	ScavTrap::setName("_clap_name");
	ScavTrap::setHitPoints(FragTrap::getHitPoints());
	FragTrap::setEnergyPoints(ScavTrap::getEnergyPoints());
	ScavTrap::setAttackDamage(FragTrap::getAttackDamage());
}

DiamondTrap::DiamondTrap(const std::string newName)
{
	name = newName;
	FragTrap::setName(newName + "_clap_name");
	ScavTrap::setName(newName + "_clap_name");
	ScavTrap::setHitPoints(FragTrap::getHitPoints());
	FragTrap::setEnergyPoints(ScavTrap::getEnergyPoints());
	ScavTrap::setAttackDamage(FragTrap::getAttackDamage());
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
{
	name = other.name;
	FragTrap::setName(other.name + "_clap_name");
	ScavTrap::setName(other.name + "_clap_name");
	ScavTrap::setHitPoints(other.FragTrap::getHitPoints());
	FragTrap::setEnergyPoints(other.ScavTrap::getEnergyPoints());
	ScavTrap::setAttackDamage(other.FragTrap::getAttackDamage());
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap &other)
{
	name = other.name;
	FragTrap::setName(other.name + "_clap_name");
	ScavTrap::setName(other.name + "_clap_name");
	ScavTrap::setHitPoints(other.FragTrap::getHitPoints());
	FragTrap::setEnergyPoints(other.ScavTrap::getEnergyPoints());
	ScavTrap::setAttackDamage(other.FragTrap::getAttackDamage());
	return *this;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::takeDamage(unsigned int amount)
{
	FragTrap::takeDamage(amount);
}
void DiamondTrap::beRepaired(unsigned int amount)
{
	FragTrap::beRepaired(amount);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap: " << name << " ClapTrap.name: " << ScavTrap::getName();
}
