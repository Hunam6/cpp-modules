#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
	std::array<Contact, 8> contacts;
public:
	PhoneBook() {}
	void add();
	void search(std::string rawContact);
	void exit();
};

#endif