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
	diamondTrap.attack("Mario"); // not enough energyPoints left
	diamondTrap.takeDamage(2);
	diamondTrap.beRepaired(1); // not enough energyPoints left
	diamondTrap.highFivesGuys();
	diamondTrap.whoAmI();
}
