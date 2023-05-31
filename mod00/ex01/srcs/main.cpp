#include "PhoneBook.hpp"
#include <iostream>

std::string truncate(std::string str)
{
	if (str.size() <= 10)
		return str;
	return str.substr(0, 9) + ".";
}

void getUserInput(PhoneBook &phoneBook)
{
	std::string command;
	std::cout << "> ";
	while (std::getline(std::cin, command))
	{
		if (command.compare("ADD") == 0)
			phoneBook.add();
		else if (command.compare("SEARCH") == 0)
			phoneBook.search();
		else if (command.compare("EXIT") == 0)
			phoneBook.exit();
		std::cout << "> ";
	}
}

int main()
{
	PhoneBook phoneBook;
	std::cout << "Empty Phone Book created...\n\n";
	std::cout << "Please enter one of the supported commands:\n";
	std::cout << "\tADD: save a new contact\n";
	std::cout << "\tSEARCH: display a specific contact\n";
	std::cout << "\tEXIT: exit the program, contacts lost\n";
	getUserInput(phoneBook);
}