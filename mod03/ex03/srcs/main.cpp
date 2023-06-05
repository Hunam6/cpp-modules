#include "DiamondTrap.hpp"
#include <iostream>

int main(void)
{
	DiamondTrap diamondTrap("Luigi");

	diamondTrap.attack("Mario");
	diamondTrap.attack("Mario");
	diamondTrap.attack("Mario");
	diamondTrap.attack("Mario");
	diamondTrap.attack("Mario");
	diamondTrap.beRepaired(1);
	diamondTrap.attack("Mario");
	diamondTrap.attack("Mario");
	diamondTrap.attack("Mario");
	diamondTrap.attack("Mario");
	diamondTrap.attack("Mario");
	diamondTrap.takeDamage(2);
	diamondTrap.beRepaired(1);
	diamondTrap.highFivesGuys();
}
