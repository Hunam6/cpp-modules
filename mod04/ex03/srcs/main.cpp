#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include <iostream>

int main()
{
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	// src->learnMateria(new AMateria()); will not work
	ICharacter *me = new Character("me");
	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter *bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;

	AMateria *shouldBeZero = src->createMateria("mhhhh");
	std::cout << "shouldBeZero: " << shouldBeZero << "\n";
	delete src;
	delete shouldBeZero;
	ICharacter *henry = new Character("henry");
	Cure *newCure = new Cure();
	henry->equip(newCure);
	henry->use(0, *henry);
	henry->use(1, *henry);
	delete henry;
}
