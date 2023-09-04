#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	ScavTrap scavTrap("Luigi");

	scavTrap.attack("Mario");
	scavTrap.attack("Mario");
	scavTrap.attack("Mario");
	scavTrap.attack("Mario");
	scavTrap.attack("Mario");
	scavTrap.beRepaired(1);
	scavTrap.attack("Mario");
	scavTrap.attack("Mario");
	scavTrap.attack("Mario");
	scavTrap.attack("Mario");
	scavTrap.attack("Mario"); // not enough energyPoints left
	scavTrap.takeDamage(2);
	scavTrap.beRepaired(1); // not enough energyPoints left
	scavTrap.guardGate();
}
