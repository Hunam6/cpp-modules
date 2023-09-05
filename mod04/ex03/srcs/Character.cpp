#include "Character.hpp"
#include <iostream>

Character::Character()
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	inventoryLen = 0;
}

Character::Character(std::string name)
	: name(name)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	inventoryLen = 0;
}

Character::Character(Character &other)
{
	for (int i = 0; i < inventoryLen; i++)
		delete inventory[i];
	for (int i = 0; i < 4; i++)
		inventory[i] = other.inventory[i]->clone();
	inventoryLen = other.inventoryLen;
}

Character::~Character()
{
	for (int i = 0; i < inventoryLen; i++)
		delete inventory[i];
}

Character &Character::operator=(Character &other)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = other.inventory[i];
	inventoryLen = other.inventoryLen;
	return *this;
}

std::string const &Character::getName() const
{
	return name;
}

void Character::equip(AMateria *m)
{
	if (inventoryLen == 4)
		return;

	for (int i = 0; i < 4; i++)
		if (inventory[i] == NULL)
		{
			inventory[inventoryLen++] = m;
			break;
		}
}

void Character::unequip(int idx)
{
	if (idx > 3 || inventory[idx] == NULL)
		return;
	inventory[idx] = NULL;
	inventoryLen--;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx > 3 || inventory[idx] == NULL)
		return;
	inventory[idx]->use(target);
}
