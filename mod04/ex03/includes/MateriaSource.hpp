#pragma once
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria *inventory[4];
	int inventoryLen;

public:
	MateriaSource() : inventoryLen(0) {}
	~MateriaSource();

	void learnMateria(AMateria *);
	AMateria *createMateria(std::string const &type);
};
