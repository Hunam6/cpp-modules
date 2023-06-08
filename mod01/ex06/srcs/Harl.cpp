#include "Harl.hpp"
#include <iostream>

Harl::Harl(std::string level)
{
	levelsName[0] = "DEBUG";
	levelsName[1] = "INFO";
	levelsName[2] = "WARNING";
	levelsName[3] = "ERROR";
	for (int i = 0; i < 4; i++)
		if (level == levelsName[i])
		{
			levelThreshold = i;
			break;
		}
}

void Harl::debug()
{
	std::cout << "DEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
}

void Harl::info()
{
	std::cout << "INFO: I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n";
}

void Harl::warning()
{
	std::cout << "WARNING: I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\n";
}

void Harl::error()
{
	std::cout << "ERROR: This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(std::string level)
{
	void (Harl::*levelsFunction[])() =
		{&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	int levelIdx = 0;
	for (; levelIdx < 4; levelIdx++)
		if (level == levelsName[levelIdx])
			break;

	if (levelIdx > levelThreshold)
		return;
	switch (levelIdx)
	{
	case 0:
		(this->*levelsFunction[0])();
		break;
	case 1:
		(this->*levelsFunction[1])();
		break;
	case 2:
		(this->*levelsFunction[2])();
		break;
	case 3:
		(this->*levelsFunction[3])();
		break;
	}
}
