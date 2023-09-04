#include "Zombie.hpp"
#include <iostream>

Zombie *zombieHorde(int N, std::string name);

int main()
{
	const int hordeSize = 6;
	Zombie *horde = zombieHorde(hordeSize, "Horde member");
	for (int i = 0; i < hordeSize; i++)
		horde[i].announce();
	delete[] horde;
	horde = zombieHorde(0, "None");
}
