#pragma once
#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl
{
private:
	std::string levelsName[4];
	int levelThreshold;
	void debug();
	void info();
	void warning();
	void error();

public:
	Harl() {}
	Harl(std::string level);
	~Harl() {}
	void complain(std::string level);
};

#endif
