#pragma once
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
	Character(std::string newName) : name(newName) {}
	Character(Character &other);
	~Character();

	Character &operator=(Character &other);

	std::string const &getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);
};
