#include "Zombie.hpp"
#include "zombieHorde.hpp"
#include <iostream>

int main()
{
	const int hordeSize = 6;
	Zombie *horde = zombieHorde(hordeSize, "Horde member");
	for (int i = 0; i < hordeSize; i++)
		horde[i].announce();
	delete[] horde;
}
