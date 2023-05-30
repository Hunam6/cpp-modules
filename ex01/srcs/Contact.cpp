#include "../includes/Contact.hpp"

Contact::Contact(std::string newFirstName, std::string newLastName, std::string newNickName, std::string newPhoneNumber, std::string newDarkestSecret)
{
	firstName = newFirstName;
	lastName = newLastName;
	nickName = newNickName;
	phoneNumber = newPhoneNumber;
	darkestSecret = newDarkestSecret;
}
