#include "PhoneBook.hpp"
#include "main.hpp"
#include <iostream>
#include <iomanip>

void PhoneBook::add()
{
	if (current == 8 || current == -1)
		current = 0;
	contacts[current].firstName.clear();
	contacts[current].lastName.clear();
	contacts[current].nickname.clear();
	contacts[current].phoneNumber.clear();
	contacts[current].darkestSecret.clear();

	std::cout << "Enter the contact informations:\n";
	while (contacts[current].firstName.size() == 0)
	{
		std::cout << "First name: ";
		std::getline(std::cin, contacts[current].firstName);
	}
	while (contacts[current].lastName.size() == 0)
	{
		std::cout << "Last name: ";
		std::getline(std::cin, contacts[current].lastName);
	}
	while (contacts[current].nickname.size() == 0)
	{
		std::cout << "Nickname: ";
		std::getline(std::cin, contacts[current].nickname);
	}
	while (contacts[current].phoneNumber.size() == 0)
	{
		std::cout << "Phone number: ";
		std::getline(std::cin, contacts[current].phoneNumber);
	}
	while (contacts[current].darkestSecret.size() == 0)
	{
		std::cout << "Darkest secret: ";
		std::getline(std::cin, contacts[current].darkestSecret);
	}
	current++;
	std::cout << "Contact added\n";
}

void PhoneBook::search()
{
	if (current == -1)
	{
		std::cout << "No contact registered.\n";
		return;
	}

	std::cout << "     Index|First name| Last name|  Nickname\n";
	std::cout << "----------|----------|----------|----------\n";
	int i = 0;
	for (; contacts[i].firstName.size() > 0 && i < 8; i++)
	{
		std::cout << std::setw(10) << std::right << i << "|";
		std::cout << std::setw(10) << std::right << truncate(contacts[i].firstName) << "|";
		std::cout << std::setw(10) << std::right << truncate(contacts[i].lastName) << "|";
		std::cout << std::setw(10) << std::right << truncate(contacts[i].nickname) << "\n";
	}

	std::string raw_index;
	while (!checkIdx(raw_index, i - 1))
	{
		std::cout << "Enter the index of the contact to display: ";
		std::getline(std::cin, raw_index);
	}
	contacts[std::stoi(raw_index)].print();
}

void PhoneBook::exit()
{
	std::exit(0);
}

bool PhoneBook::checkIdx(std::string rawIdx, int maxIdx)
{
	if (rawIdx.empty())
		return false;
	int idx;
	try
	{
		idx = std::stoi(rawIdx);
	}
	catch (...)
	{
		return false;
	}
	if (idx < 0 || idx > maxIdx)
		return false;
	return true;
}
