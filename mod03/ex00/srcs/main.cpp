#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
	ClapTrap clapTrap("Luigi");

	clapTrap.attack("Mario");
	clapTrap.attack("Mario");
	clapTrap.attack("Mario");
	clapTrap.attack("Mario");
	clapTrap.attack("Mario");
	clapTrap.beRepaired(1);
	clapTrap.attack("Mario");
	clapTrap.attack("Mario");
	clapTrap.attack("Mario");
	clapTrap.attack("Mario");
	clapTrap.attack("Mario");
	clapTrap.takeDamage(2);
	clapTrap.beRepaired(1);
}
