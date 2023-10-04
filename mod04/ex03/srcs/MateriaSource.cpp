#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
	: inventoryLen(0) {}

MateriaSource::MateriaSource(MateriaSource &other)
	: inventoryLen(other.inventoryLen)
{
	for (int i = 0; i < inventoryLen; i++)
		inventory[i] = other.inventory[i];
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < inventoryLen; i++)
		delete inventory[i];
}

MateriaSource &MateriaSource::operator=(MateriaSource &other)
{
	inventoryLen = other.inventoryLen;
	for (int i = 0; i < inventoryLen; i++)
		inventory[i] = other.inventory[i];
	return *this;
}

void MateriaSource::learnMateria(AMateria *materia)
{
	if (inventoryLen == 4)
		return;

	for (int i = 0; i < 4; i++)
		if (inventory[i] == NULL)
		{
			inventory[inventoryLen++] = materia;
			break;
		}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < inventoryLen; i++)
	{
		if (inventory[i]->getType() == type)
			return inventory[i]->clone();
	}
	return 0;
}
