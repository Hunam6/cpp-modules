#pragma once
#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"
#include <string>

class HumanB
{
private:
	std::string name;
	Weapon *weapon;

public:
	HumanB(std::string newName) : name(newName), weapon(NULL) {}
	~HumanB() {}
	void attack();
	void setWeapon(Weapon &newWeapon);
};

#endif
