#pragma once
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
	std::array<Contact, 8> contacts;
	int current;
public:
	PhoneBook();
	void add();
	void search();
	void exit();
	bool checkIdx(std::string rawIdx, int maxIdx);
};

#endif