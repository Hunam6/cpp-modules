#pragma once
#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
private:
	AMateria *inventory[4];
	int inventoryLen;
	std::string name;

public:
	Character();
	Character(std::string name);
	Character(Character &other);
	~Character();

	Character &operator=(Character &other);

	std::string const &getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);
};

#endif
