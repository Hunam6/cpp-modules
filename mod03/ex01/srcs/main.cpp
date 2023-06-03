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
	scavTrap.attack("Mario");
	scavTrap.takeDamage(2);
	scavTrap.beRepaired(1);
	scavTrap.guardGate();
}
