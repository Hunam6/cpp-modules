#pragma once
#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria *inventory[4];
	int inventoryLen;

public:
	MateriaSource();
	MateriaSource(MateriaSource &other);
	~MateriaSource();

	MateriaSource &operator=(MateriaSource &other);

	void learnMateria(AMateria *);
	AMateria *createMateria(std::string const &type);
};

#endif
