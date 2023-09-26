#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("presidential pardon", 25, 5),
	  target("nobody") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("presidential pardon", 25, 5),
	  target(target) {}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	AForm::execute(executor);
	std::cout << target << " has been pardoned by Zaphod Beeblebrox\n";
}
