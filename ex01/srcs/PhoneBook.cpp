#include "../includes/PhoneBook.hpp"
#include <iostream>

void PhoneBook::add()
{
	std::cout << "ADD called\n";
}

void PhoneBook::search(std::string rawContact)
{
	(void) rawContact;
	std::cout << "SEARCH called\n";
}

void PhoneBook::exit()
{
	std::cout << "EXIT called\n";
}

static void getUserInput(PhoneBook *phoneBook)
{
	std::string command;
	std::cout << "> ";
	while (std::getline(std::cin, command))
	{
		if (command.compare("ADD") == 0)
			phoneBook->add();
		else if (command.compare("SEARCH") == 0)
			phoneBook->search(command); //TODO: replace `command`
		else if (command.compare("EXIT") == 0)
			phoneBook->exit();
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
	getUserInput(&phoneBook);
}