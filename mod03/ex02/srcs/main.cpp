#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
	FragTrap fragTrap("Luigi");

	fragTrap.attack("Mario");
	fragTrap.attack("Mario");
	fragTrap.attack("Mario");
	fragTrap.attack("Mario");
	fragTrap.attack("Mario");
	fragTrap.beRepaired(1);
	fragTrap.attack("Mario");
	fragTrap.attack("Mario");
	fragTrap.attack("Mario");
	fragTrap.attack("Mario");
	fragTrap.attack("Mario");
	fragTrap.takeDamage(2);
	fragTrap.beRepaired(1);
	fragTrap.highFivesGuys();
}
