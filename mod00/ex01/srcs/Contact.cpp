#include "Contact.hpp"
#include <iostream>

Contact::Contact() {}

void Contact::print()
{
	std::cout << "Contact card: \n";
	std::cout << "\tFirst name: " << firstName << "\n";
	std::cout << "\tLast name: " << lastName << "\n";
	std::cout << "\tNickname: " << nickname << "\n";
	std::cout << "\tPhone number: " << phoneNumber << "\n";
	std::cout << "\tDarkest secret: " << darkestSecret << "\n";
}
