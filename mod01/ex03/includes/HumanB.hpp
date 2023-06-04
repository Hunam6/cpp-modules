#pragma once
#ifndef HUMANB_HPP
#define HUMANB_HPP

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
