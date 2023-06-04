#pragma once
#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA
{
private:
	std::string name;
	Weapon &weapon;

public:
	HumanA(std::string newName, Weapon &newWeapon) : name(newName), weapon(newWeapon) {}
	~HumanA() {}
	void attack();
};

#endif
