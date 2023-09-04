#pragma once
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts[8];
	int current;
	bool checkIdx(std::string rawIdx, int maxIdx);

public:
	PhoneBook();
	void add();
	void search();
};

#endif
